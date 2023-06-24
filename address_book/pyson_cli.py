import sys
from pyson_parser import main

def print_dict(lst):
    if not isinstance(lst,  dict):
        raise TypeError("")
    for key in lst:
            print(key, ":")
            if isinstance(lst[key], dict):
                for key1 in lst[key]:
                    print("\t", key1, ":", lst[key][key1])
            else:
                print("\t", lst[key])

def cli_interface():

    cond2 = False
    if sys.argv[-1] == "srch":
        cond2 = True
        sys.argv.pop()
        key = sys.argv[-1]

    comm_lst = sys.argv

    comm_lst[2:] = [" ".join(comm_lst[2:])]
    comm_lst.append("exit")
    comm_lst.pop(0)

    comm_lst = list(filter(lambda x : bool(x), comm_lst))
    cond1 = len(comm_lst) == 2
#    cond2 = len(sys.argv) == 3
#    if cond2:
#        key = sys.argv[2]

    def my_input(*args):
        return comm_lst.pop(0)

    main.input = my_input

    def my_print(*args):
        pass


    main.print = my_print
    main.pprint = my_print

    dct = main.main()

    
    if cond1:
        print_dict(dct)
    if cond2:
        print_dict(dct[key])



if "__main__" == __name__:
	cli_interface()





