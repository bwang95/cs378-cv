function newDir(){
	mkdir build
	cd build
}
function compile(){
	cmake ..
	make -j8
}
function remake(){
	clean
	newDir
	compile
}

./clean.sh
remake