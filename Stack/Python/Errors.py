"""Definition of Custom errors and exceptions
"""
class WordNotProvidedError(Exception):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)