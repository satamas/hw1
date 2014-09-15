#/bin/sh

mkdir -p .out
cd .out
cmake ../
make

for file in ../Tests/*.in
do	
	echo "${file}"
	filename="${file%.*}"
	./hw1 < "${filename}.in" > "${filename}.out"
	cmp "${filename}.out" "${filename}.ans"
done

cd ..
rm -rf .out
