#include<iostream>
#include<gmp.h>
#include<gmpxx.h>

using namespace std;

int main (int argc, char **argv) {

	double d = 0.1;
    
	mpz_t a,b,c;
    mpz_inits(a,b,c,NULL);

	mpq_t sr;
	mpq_init(sr);
	mpf_t df;
	mpf_init(df);
	mpf_set_d(df,d);
	mpq_set_f(sr,df);

    mpz_set_str(a, "1234", 10);
    mpz_set_str(b,"-5678", 10); //Decimal base

    mpz_add(c,a,b);

    cout<<"\nThe exact result is:";
    mpz_out_str(stdout, 10, c); //Stream, numerical base, var
    cout<<endl;

    mpz_abs(c, c);
    cout<<"The absolute value result is:";
    mpz_out_str(stdout, 10, c);
    cout<<endl;

    //cin.get();

	mpq_class q(sr);
	//mpq_init(q);
	mpz_set(a,q.get_num_mpz_t());
	mpz_set(b,q.get_den_mpz_t());
	mpz_out_str(stdout,10,a);
	cout << '/';
	mpz_out_str(stdout,10,b);

    return 0;
}

