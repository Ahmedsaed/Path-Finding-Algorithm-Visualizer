import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from helper_function import run_test

input = """Arad
Bucharest
A* Search"""

expected = """
Arad --> Sibiu --> Rimnicu Vilcea --> Pitesti --> Bucharest
"""

run_test(input, expected)
