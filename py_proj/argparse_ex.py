import argparse
parser = argparse.ArgumentParser()
prop_id = None

parser = argparse.ArgumentParser()
parser.add_argument("--propertyid", required=False)
parser.add_argument("--force", required=False)
try:
    split_args = shlex.split(args[0])
except IndexError:
    split_args = []

args2 = parser.parse_args(split_args)

if args2['propertyid']:
