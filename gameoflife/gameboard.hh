#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <cstring>
#include <sstream>
#include <string> 

class GameBoard {
    private:
        int w, bw, h, bh, ngen, pgen;
        int *L;
        int *next;

        int next_elem(const int x, const int y) const {
            if (x < -1 || y < -1 || x > bw || y > bh) 
                throw std::out_of_range("Attempting to access an element out of bounds");
            
            return next[(x+1)*bw+(y+1)];
        }

        int& next_elem(const int x, const int y) {
            if (x < -1 || y < -1 || x > bw || y > bh) 
                throw std::out_of_range("Attempting to access an element out of bounds");

            return next[(x+1)*bw+(y+1)];
        }

        int checkNeighbors(const int x, const int y) const {
            int count = 0;
            for (int i = x-1; i <= x+1; i++) {
                for (int j = y-1; j <= y+1; j++) {
                    if ((*this)(i, j) == 1)
                        count++;
                }
            }

            return count;
        }

        void loop() {
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < h; j++) {
                    int num_neighbors = checkNeighbors(i, j);

                    if (num_neighbors < 2)
                        next_elem(i, j) = 0;
                    else if (num_neighbors = 2 || num_neighbors == 3 && (*this) (i, j) == 1)
                    ;
                    else if (num_neighbors > 3)
                        next_elem(i, j) = 0;
                    else if (num_neighbors == 3 && (*this) (i, j) == 0)
                        next_elem(i, j) = 1;
                }
            }
            std::swap(L, next);
        }

    public:
        GameBoard(const char filepath[]) {
            std::ifstream f(filepath);
            std::string line;
            std::stringstream ss;
            int counter = 0;
            int j = 0;
            bool first = true;
            if (f.is_open()) {
                while (std::getline(f, line)) {
                    if (first) {
                        std::cout<< "In first!!!" <<std::endl;
                        ss << line;
                        ss >> w >> h >> ngen >> pgen;
                        bw = w+2; bh = h+2;
                        L = new int[bw*bh];
                        next = new int[bw*bh];

                        std::memset(L, 0, bw*bh*sizeof(int));
                        std::memset(next, 0, bw*bh*sizeof(int));

                        first = false;
                        counter++;
                        ss.clear();
                        continue;
                    }
                    if (line.length() != w) {
                        throw std::runtime_error("Input row has too many or too few dots");
                    } else if (counter > h) {
                        throw std::runtime_error("Too many input rows");
                    }

                    for (int i = 0; i < line.length(); i++) {
                        // if (line[i] == '*') 
                        //     (*this)(i, j) = 1;
                        if (line[i] == '.')
                            (*this)(i, j) = 0;
                        else 
                            (*this)(i, j) = 1;
                        // else {
                        //     std::cout << line << std::endl;
                        //     std::cout << line[i] << std::endl;
                        //     std::cout << i <<std::endl;
                        //     throw std::runtime_error("Input row contains characters other than * or . ");
                        // }
                    }
                    j++;
                    counter++;
                }
                if (counter < h) {
                    throw std::runtime_error("Too few input rows");
                }

                f.close();
            }
            print();
        }

        void run() {
            print();
            for (int i = 0; i < ngen; i++) {
                if ( i % pgen == 0)
                    print();
                loop();
            }
        }

        int operator ()(const int x, const int y) const {
            if (x < -1 || y < -1 || x > bw || y > bh) 
                throw std::out_of_range("Attempting to access an element out of bounds");

            return L[(x+1)*bw+(y+1)];
        }

        int& operator ()(const int x, const int y) {
            if (x < -1 || y < -1 || x > bw || y > bh) 
                throw std::out_of_range("Attempting to access an element out of bounds");

            return L[(x+1)*bw+(y+1)];
        }

        void print() const {
            for (int j = 0; j < h; j++) {
                for (int i = 0; i < w; i++) {
                    if ((*this) (i, j) == 1)
                        std::cout << "* ";
                    else
                        std::cout << ". ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }

        friend std::ostream& operator <<(std::ostream& s, const GameBoard& gb) {
            gb.print();
            return s;
        }   
};