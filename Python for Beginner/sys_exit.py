import sys

if len(sys.argv) != 2:
    print("Error Missing Command line Argument ")
    sys.exit(1)

print(f"Hello, {sys.argv[1]}")
sys.exit(0)