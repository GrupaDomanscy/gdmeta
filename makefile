files = src/main.c src/string.c

all:
	make clean
	make build

clean:
	rm -rf build

build:
	mkdir build
	rm -rf src/templates
	mkdir src/templates
	xxd -i -n array_h_template src/raw_templates/template_array.h src/templates/array_h.h
	xxd -i -n array_c_template src/raw_templates/template_array.c src/templates/array_c.h
	xxd -i -n string_c_template src/raw_templates/string.c src/templates/string_c.h
	xxd -i -n string_h_template src/raw_templates/string.h src/templates/string_h.h
	gcc -g -o build/gdmeta $(files)

install:
	mv ./build/gdmeta /usr/bin/
