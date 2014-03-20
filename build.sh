
function clean(){
	rm -rf build
}
function newDir(){
	mkdir build
	cd build
}
function compile(){
	cmake ../src
	make -j8
}
function remake(){
	clean
	newDir
	compile
}

cd CornerDetection
remake
cd ../../Display
remake
cd ../../FeatureDetection
remake
cd ../../GrayScale
remake
cd ../..