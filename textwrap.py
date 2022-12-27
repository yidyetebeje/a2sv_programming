import textwrap

def wrap(string, max_width):
    result = ""
    for i in range(0, len(string), max_width):
        result += (string[i:i + max_width] + "\n")
    return result

if __name__ == '__main__':
