import os
import subprocess
import difflib
import re
import inspect


def run_test(input, expected):
    filename = os.path.basename(inspect.stack()[1].filename)

    # run your compiled executable and capture its output
    app_process = subprocess.run("./build/shortest_path", input=input, capture_output=True, text=True)
    app_output = app_process.stdout.strip()
    expected = expected.strip()

    # compare the output of your shell and bash
    if expected in app_output:
        print(f"integration test {filename} passed!")
    else:
        print(f"integration test {filename} failed.")
        print("app output: \n", app_output)
        print("expected output: \n", expected)
        dif = difflib.Differ()
        shell_diff = dif.compare(app_output.splitlines(), expected.splitlines())
        print("\n".join(shell_diff))
