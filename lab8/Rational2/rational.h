// rational.h

class Rational {
  public:
    Rational();
    Rational(int, int);
    ~Rational();
    
    int getNumer();
    int getDenom();
    
    void setNumer(int);
    void setDenom(int);
    void setRational(int numer, int denom);
    
    void reduce();
    
    Rational operator+(Rational);
    Rational operator-(Rational);
    Rational operator*(Rational);
    Rational operator/(Rational);
    
	friend std::ostream& operator<<(std::ostream&, const Rational&);
	friend std::istream& operator>>(std::istream&, Rational&);

  private:
    int numer;
    int denom;
};

