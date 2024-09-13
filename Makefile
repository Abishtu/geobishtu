
configure:
	cd build && cmake ../

run: run
	bin/geobishtu

build: configure
	cd build && cmake --build . && mv geobishtu ../bin/geobishtu

clean:
	rm bin/* && rm debug/*
