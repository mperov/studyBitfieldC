all: bitfield

bitfield: bitfield.c
	gcc bitfield.c -o bitfield

run: bitfield
	./bitfield

clean:
	rm -f ./bitfield
