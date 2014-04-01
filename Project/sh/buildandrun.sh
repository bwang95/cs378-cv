function clean(){
	rm -rf build
}
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

remake
./build/Project ImgDB/DSC02388.JPG ImgDB/DSC02389.JPG 
