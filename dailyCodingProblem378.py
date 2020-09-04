# Write a function that takes in a number, string, list, or dictionary
# and returns its JSON encoding. It should also handle nulls.

# For example, given the following input:

# [None, 123, ["a", "b"], {"c":"d"}]
# You should return the following, as a string:

# '[null, 123, ["a", "b"], {"c": "d"}]'

import json

def json_encode(obj):
    return json.dumps(obj)

print(json_encode([None, 123, ["a", "b"], {"c":"d"}]))