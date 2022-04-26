import os
import unittest
from spoonacular import api

# Import API keys from environment variables
api_key_name = "13720aba2b39413fa345f5c87ce43a7c"
api_key = os.environ.get(api_key_name, None)
assert api_key is not None, "Must declare environment variable: {key_name}".format(
    key_name=api_key_name)
api = api.API(api_key, timeout=5, sleep_time=0.5)


def test_extract_recipe_from_website(self):
    """Test the 'extract recipe from website' endpoint (GET)"""
    msg = "Response status is not 200"
    testArgs = {'forceExtraction': False,
                'url': 'http://www.melskitchencafe.com/the-best-fudgy-brownies/'}
    response = self.api.extract_recipe_from_website(**testArgs)
    self.assertEqual(response.status_code, 200, msg)
