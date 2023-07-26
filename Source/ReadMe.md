# File/Directory Structure

	CA
		Common
		OCS
		OpenDRIVE
		OSM
		CA.pro
		main.cpp
		ReadMe.md
		swift-gnss.csv
	
	In any directory outside of CA directory
		PROJ (need to clone from github)
			

	CAUTION: Don't copy any other files into CA directory

# Prerequiresties 
	PROJ

## On Linux

### Install sqlite3
	sudo apt install sqlite3 libsqlite3-dev
	
### Install libpq-dev
	sudo apt install libpq-dev
	
### Install libqt5sql5-psql
	sudo apt install libqt5sql5-psql
	
### Install postgresql-12 postgresql-client-12
	https://computingforgeeks.com/install-postgresql-12-on-ubuntu/
	
### Install postgis
	https://computingforgeeks.com/how-to-install-postgis-on-ubuntu-debian/
	
### Install pgadmin4
	https://www.tecmint.com/install-postgresql-and-pgadmin-in-ubuntu/

### Checkout PROJ sources in External directory
		in Any folder
	git clone https://github.com/OSGeo/PROJ.git
	cd PROJ

### Build
	./autogen.sh
	./configure --disable-tiff --without-curl
	make
	sudo make install
	sudo ldconfig

### ???
	export PROJ_LIB=/usr/share/proj

### Install gdal-bin, libgdal-dev
	sudo add-apt-repository ppa:ubuntugis/ppa
	sudo apt install gdal-bin
	sudo apt install libgdal-dev
	export CPLUS_INCLUDE_PATH=/usr/include/gdal
	export C_INCLUDE_PATH=/usr/include/gdal
	export GDAL_DATA=/usr/share/gdal

### Profile
	Add export statements into /etc/profile.d/ods-env.sh

## On Windows

	use OSGeo4W64

