from __future__ import absolute_import, print_function
import os

if __name__== "__main__":
    value = '~/.ssh/id_rsa.pub'
    value = os.path.expanduser(value)
    try:
        if value == '':
            print(False)
            exit(1)

        with open(value) as file_:
            self.value = file_.read()
        print(True)
        exit(0)
    except Exception as exc:
        print(exc)
        print(False)
        exit(1)
