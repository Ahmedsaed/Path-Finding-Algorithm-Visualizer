import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from helper_function import run_test

input = """Arad
Bucharest
Breath First Search"""

expected = """
Arad --> Sibiu --> Fagaras --> Bucharest
"""

run_test(input, expected)
