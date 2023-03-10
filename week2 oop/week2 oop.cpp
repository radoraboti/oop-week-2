#include <iostream>
#include <fstream>

const int movieNameLength = 255;

enum GENRE
{
    Action,
    Adventure,
    Comedy,
    Drama,
    Fantasy,
    Horror,
    Romance,
    Thriller

};

struct Movie
{
    char movieName[movieNameLength];
    int year;
    float length;
    GENRE genre;

};

void genreOutput(GENRE m, std::ostream& print)
{
    switch (m) {
    case Action:
        print << "Action";
        break;
    case Adventure:
        print << "Adventure";
        break;
    case Comedy:
        print << "Comedy";
        break;
    case Drama:
        print << "Drama";
        break;
    case Fantasy:
        print << "Fantasy";
        break;
    case Horror:
        print << "Horror";
        break;
    case Romance:
        print << "Romance";
        break;
    case Thriller:
        print << "Thriller";
        break;
    }
}

void printMovie(const Movie& m, std::ostream& print)
{
    print<< "Name: " << m.movieName << ' ';
    print << "Release Year: " << m.year << ' ';
    print << "Length: " << m.length << ' ';
    print << "Genre: ";
    genreOutput(m.genre, print);
    print << ' ' << std::endl;

}

//void writeMovies(const Movie& m, std::ofstream& File)
//{
//
//    File << "Name: " << m.movieName << ' ';
//    File << "Release Year: " << m.year << ' ';
//    File << "Length: " << m.length << ' ';
//    File << "Genre: ";
//    genreOutput(m.genre, File);
//    File << ' '<< std::endl;
//
//}

int main()
{
    Movie movie1 = { "Titanic", 1997, 3.25, GENRE::Romance };
    Movie movie2 = { "Die hard", 1988, 2.2, GENRE::Action };
    Movie movie3 = { "The last of us", 2023, 1, GENRE::Thriller };
    Movie movie4 = { "Jurassic Park", 1993, 2.15, GENRE::Adventure };
    Movie movie5 = { "Scream", 1996, 2, GENRE::Horror };
    Movie movie6 = { "The notebook", 2004, 2, GENRE::Romance };
    Movie movie7 = { "The silence of the lambs", 1991, 1.9, GENRE::Horror };


    Movie moviearr[] = { movie1, movie2, movie3, movie4, movie5, movie6, movie7 };

    int size = sizeof(moviearr)/sizeof(Movie);
   
    for (size_t i = 0; i < size; i++)
    {
        printMovie(moviearr[i],std::cout);
        std::cout << std::endl;
    }

    std::ofstream File("movies.txt");

    for (size_t i = 0; i < size; i++)
    {
        printMovie(moviearr[i], File);
        
    }

    File.close();
}

