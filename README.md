# opendrivesystem

Grid & Geographic Coordinate System


NOTE: There is no POPULAR system which can handle several & different coordinate systems for whole data at the same time.
But it’s possible to handle several & different systems.
Just the application would be MORE complicated.

1. What coordinate system should we use ? 
For GPS/CSV data : WGS-84 (EPSG:4326) coordinate system (latitude & longitude : degree)
For OpenDRIVE content : must be any/certain projected coordinate system, that is METER coordinate system
For example, EPSG:3857, …

We have to convert from WGS-84 to certain projected coordinate system like EPSG:3857

The best ideal way to choose projected coordinate system for OpenDRIVE is to refer every countries GIS POLICY.
	So, we can determine projected coordinate system for OpenDRIVE corresponding to WGS-84 coordinate system
	using POLICY.

We chose EPSG:3112 for Australia
That is GDA94 / Geoscience Australia Lambert
Geographic Coordinate System is presented by several ways
- Name
- EPSG number
- WKT
- PROJ4 expression
For example, “GDA94 / Geoscience Australia Lambert” => EPSG:3112 => PROJ4 : "+proj=lcc +lat_1=-18 +lat_2=-36 +lat_0=0 +lon_0=134 +x_0=0 +y_0=0 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs"

In future, we can use different systems for the world. But there would be some problems/difficulty.
- Handling overlapped area between different systems’ grids
- Calculating distance between them

OpenDRIVE contains PROJ4 expression in specifications.

We use PROJ4 library which supports transformation between any coordinate system.

2. Grid
We split the world by grid.
Grid is squared area
Grid is presented by row & col
Row = y / GRID_SQUARE_AREA_SIZE
Col = x / GRID_SQUARE_AREA_SIZE
