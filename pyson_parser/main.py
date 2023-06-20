from pprint import pprint
import pyson_parser

class DB:
    def __init__(self, kwargs):
        self.__dict__.update(kwargs)

def check_command(comm):
    for i in "()[]!@#$%^&*/*+<>":
        if i in comm:
            raise Exception("")

def mutate_command(comm):
    ind = comm.find("=")
    if ind == -1:
        left = comm[:]
        right = ""
    else:
        left = comm[:ind]
        right = comm[ind:]

    left = left.replace(" ","")
    tmp = left.split(".")

    if len(tmp) > 1:
        tmp[1:] = list(map(lambda x: f'["{x}"]', tmp[1:]))
        left = "".join(tmp)


    return left + right


def command_mode(file_name):
    try:
        with open(file_name, "r") as f:
            text = f.read()
    except FileNotFoundError:
        with open(file_name,"w") as f:
            f.write("{}")

        with open(file_name, "r") as f:
            text = f.read()

    try:
        db = pyson_parser.load(text.replace("'",'"'))
    except Exception:
        print("Uncorrect format of text in pyson file")
        return

    obj = DB(db)



    while True:
        pprint(obj.__dict__)
        
        comm = input("Enter the command:\n")
        check_command(comm)


        if comm == "exit":
            with open(file_name, "w") as f:
                f.write(str(obj.__dict__))
            break
        try:
            if comm[:4] == "del ":
                comm = mutate_command(comm[4:])
                exec("del obj." + comm)
                continue

            comm = mutate_command(comm)
            if "=" in comm:
                exec("obj." + comm)
            else:
                eval("print(obj." + comm + ")")
        except Exception:
            print("Uncorrect command")

def main():
    while True:
        file_name = input("Enter the file name: ")
        if file_name.split(".")[-1] != "pyson":
            print("File must have format .pyson")
            continue
        break

    command_mode(file_name)




if __name__ == "__main__":
    main()