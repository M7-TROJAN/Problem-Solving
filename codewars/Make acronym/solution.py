def to_acronym(inp):
    words = inp.split()
    acronym = ''.join(word[0].upper() for word in words)
    return acronym