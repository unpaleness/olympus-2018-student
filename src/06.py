import re
import sys

def find_link(string, domain):
    regexp5 = re.compile("(?:<a.*href=[\"\'])(?:http:\/\/|https:\/\/|)([^\"\'\?\#]+)(?:\?[^\"\']+|\#[^\"\']+|[^\?\#\"\']*)(?:[\"\'])")
    rlst = list()
    if string != "":
        lst = regexp5.findall(string)
        for el in lst:
            tstr = el
            tstr = tstr.replace('www.' + domain, '')
            tstr = tstr.replace(domain, '')
            rlst.append(tstr)
    return rlst


def create_map_for_str(str, first=False):
    parts = str.split('/')
    if len(parts) == 1:
        return str
    fpart = parts[0]
    new = "/".join(parts[1:])
    if first:
        fpart = '#'
    return {fpart: create_map_for_str(new)}


def calculate_subs(string, rmap):
    if "/" + string in rmap and rmap["/" + string][0] > 0:
        return rmap
    lst = string.split('/')
    for i in range(len(lst), 0, -1):
        sub = "/" + "/".join(lst[0: i])
        if sub in rmap:
            if i == len(lst):
                rmap[sub][1] = True
                if rmap[sub][0] < 0:
                    rmap[sub][0] *= -1
            if rmap[sub][0] < 0:
                rmap[sub][0] -= 1
            else:
                rmap[sub][0] += 1
            if i == len(lst) - 1:
                if rmap[sub][0] < -1:
                    rmap[sub][0] *= -1
        else:
            if i in [len(lst)]:
                if i == len(lst):
                    rmap[sub] = [1, True]
                else:
                    rmap[sub] = [1, False]
            else:
                rmap[sub] = [-1, False]
    return rmap


def main():
    rmap = dict()
    domain = sys.stdin.readline()
    domain = domain[:len(domain) - 1]
    for line in sys.stdin:
        tlst = find_link(line, domain)
        if len(tlst) > 0:
            for link in tlst:
                if len(link) > 0:
                    if link[0] == '/':
                        if link[len(link) - 1] == '/':
                            rmap = calculate_subs(link[1:len(link) - 1], rmap)
                        else:
                            rmap = calculate_subs(link[1:], rmap)
    keys = [key for key in rmap.keys()]
    keys.sort()
    for l in range(0, len(keys)):
        lst = keys[l].split('/')
        if len(lst) > 2:
            for i in range(1, len(lst) - 1):
                sub = '/'.join(lst[0:i + 1])
                for key2 in keys[l + 1:]:
                    if key2.find(sub) != -1:
                        sub2 = '/'.join(lst[0: i + 2])
                        if key2.find(sub2) == -1:
                            if rmap[sub][0] < 0:
                                rmap[sub][0] *= -1
    for key in keys:
        if rmap[key][0] > 0:
            if rmap[key][0] > 1:
                print(key + "/:" + str(rmap[key][0]))
            if rmap[key][1]:
                print(key)

main()