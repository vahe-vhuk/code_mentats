from functools import reduce
import re



def colon_parser(data):
    if data[0] == ":":
        return [data[0], data[1:].lstrip()]


def comma_parser(data):
    if data and data[0] == ",":
        return [data[0], data[1:].strip()]



def number_parser(data):
    regex_find = re.findall("^(-?(?:[0-9]\d*)(?:\.\d+)?(?:[eE][+-]?\d+)?)",
                            data)
    if not regex_find:
        return None
    pos = len(regex_find[0])
    try:
        return [int(regex_find[0]), data[pos:].strip()]
    except ValueError:
        return [float(regex_find[0]), data[pos:].strip()]


def object_parser(data):
    if data[0] != "{":
        return None
    parse_dict = {}
    data = data[1:].strip()
    while data[0] != "}":
        res = string_parser(data)
        if res is None:
            return None
        id = res[0]
        res = colon_parser(res[1].strip())
        if res is None:
            return None
        res = parse(res[1].strip())
        if res is None:
            return None
        parse_dict[id] = res[0]
        data = res[1].lstrip()
        res = comma_parser(data)
        if res:
            data = res[1].strip()
    return [parse_dict, data[1:]]


def string_parser(data):
    if data[0] == '"':
        data = data[1:]
        pos = data.find('"')
        return [data[:pos], data[pos + 1:].strip()]


def all_parsers(*args):
    return lambda data: (reduce(lambda f, g: f if f(data) else g, args)(data))


parse = all_parsers(string_parser, object_parser, number_parser)

def load(text):
	if text == "{}":
		return dict()
	res = parse(text)
	if res[0]:
		return res[0]
	return None

