all : 1.png 2.png 3.png 4.png 5.png 6.png 7.png 8.png 9.png 10.png error_dt.png error_N.png



# imágenes para determinar el punto a

1.png : 1.dat graficar.py
	@python graficar.py "1.dat"
2.png : 2.dat graficar.py
	@python graficar.py "2.dat"
3.png : 3.dat graficar.py
	@python graficar.py "3.dat"
4.png : 4.dat graficar.py
	@python graficar.py "4.dat"
5.png : 5.dat graficar.py
	@python graficar.py "5.dat"
6.png : 6.dat graficar.py
	@python graficar.py "6.dat"
7.png : 7.dat graficar.py
	@python graficar.py "7.dat"
8.png : 8.dat graficar.py
	@python graficar.py "8.dat"
9.png : 9.dat graficar.py
	@python graficar.py "9.dat"
10.png : 10.dat graficar.py
	@python graficar.py "10.dat"
1.dat : simula.out
	@./simula.out 1e-4 50 > 1.dat
2.dat : simula.out
	@./simula.out 2e-4 50 > 2.dat
3.dat : simula.out
	@./simula.out 3e-4 50 > 3.dat
4.dat : simula.out
	@./simula.out 4e-4 50 > 4.dat
5.dat : simula.out
	@./simula.out 5e-4 50 > 5.dat
6.dat : simula.out
	@./simula.out 6e-4 50 > 6.dat
7.dat : simula.out
	@./simula.out 7e-4 50 > 7.dat
8.dat : simula.out
	@./simula.out 8e-4 50 > 8.dat
9.dat : simula.out
	@./simula.out 9e-4 50 > 9.dat
10.dat : simula.out
	@./simula.out 10e-4 50 > 10.dat


# código punto a

simula.out : pde.cpp
	@c++ pde.cpp -o simula.out

#código punto b

b.dat : b.out
	@./b.out > b.dat
b.out : b.cpp
	@c++ b.cpp -o b.out

# código punto c

c.dat : c.out
	@./c.out > c.dat
c.out : c.cpp
	@c++ c.cpp -o c.out

# respuestas punto c,b

error_dt.png error_N.png : b.dat c.dat respuestas.py
	python respuestas.py

# clean

clean : 
	@rm -f *.dat *.png *.out