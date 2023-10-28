call bin\clean

mkdir out
mkdir build

gcc -c src/main/c/binarytree.c -o out/binarytree.o -Wall -Wextra -Werror || goto :error
gcc -c src/main/c/main.c -o out/main.o -Wall -Wextra -Werror || goto :error

gcc out/binarytree.o out/main.o -o build/containermain -Wall -Wextra -Werror || goto :error
goto :success

:error
call bin\clean
exit /b 1

:success
