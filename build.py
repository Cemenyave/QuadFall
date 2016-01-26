import sys
import os

run_path = os.getcwd() + "/game"
exe_name = "quadfall.exe"

def build_game(platform, buil_dir_name):
    build_path = os.getcwd() + "/" + buil_dir_name

    if not os.path.exists(build_path):
        os.makedirs(build_path)

    os.chdir(build_path)
    os.system("cmake -G\"" + platform + "\" . ..")
    os.system("cmake --build .")
    # os.system("ctest . -C Debug -VV") #enable for unit tests
    os.chdir(run_path)
    os.system(exe_name)

