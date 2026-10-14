# files
$Entry="src/main.c";
$Out="main.exe";

# gcc compilation
gcc $Entry -o $Out *> result.txt;

#run program is successful
if($LASTEXITCODE -ne 1){
    ./main.exe push $args[0];
}
