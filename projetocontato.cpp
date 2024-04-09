/* 	No Falcon c++ dá erro na parte da conversão to_string, mas deve ser um 
 *	problema no meu programa em específico, mas testei em compiladores online 
 *	c++	e funcionou como esperado.
 */

#include <iostream>
#include <locale.h>
#include <string> 
#include <ctime>
using namespace std;

class Data
{
	private:
		int dia;
		int mes;
		int ano;
		
    public: 
    	Data(int dia, int mes, int ano) {
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
    	Data() {
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
		void setDia(int dia) {
			this->dia = dia;
		}
		void setMes(int mes) {
			this->mes = mes;
		}
		void setAno(int ano) {
			this->ano = ano;
		}
		int getDia() {
			return this->dia;
		}
		int getMes() {
			return this->mes;
		}
		int getAno() {
			return this->ano;
		}
		string getData() {
		    string sDia = to_string(this->dia);
		    string sMes = to_string(this->mes);
		    string sAno = to_string(this->ano);
		    
		    return sDia.insert(0, 2-sDia.size(),'0') + "/" +
		           sMes.insert(0, 2-sMes.size(),'0') + "/" +
			       sAno;
        }
}; 

class Contato {
  private:
		string email;
		string nome;
		int telefone;
		Data dtnasc;
		
    public: 
    	Contato(string email, string nome, int telefone, Data dtnasc) {
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = dtnasc;
		}
    	Contato() {
			this->email = "";
			this->nome = "";
			this->telefone = 0;
			this->dtnasc = Data();
		}
		void setEmail(string email) {
			this->email = email;
		}
		void setNome(string nome) {
			this->nome = nome;
		}
		void setTelefone(int telefone) {
			this->telefone = telefone;
		}
		void setDtnasc(Data dtnasc) {
			this->dtnasc = dtnasc;
		}
		string getEmail() {
			return this->email;
		}
		string getNome() {
			return this->nome;
		}
		int getTelefone() {
			return this->telefone;
		}
		Data getDtnasc() {
			return this->dtnasc;
		}
        
		string getContato() {
            string sEmail = this->email;
            string sNome = this->nome;
            string sTelefone = to_string(this->telefone);
            string sDtnasc = this->dtnasc.getData();
            string sIdade = to_string(this->getIdade());            
            
            return "Email: " + sEmail + "\nNome: " + sNome + "\nTelefone: " + sTelefone + "\nData de Nascimento: " + sDtnasc + "\nIdade atual: " + sIdade;
        }

        int getIdade() {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int anoAtual = 1900 + ltm->tm_year;

            int idade = anoAtual - this->dtnasc.getAno();
            if (ltm->tm_mon + 1 < this->dtnasc.getMes() || (ltm->tm_mon + 1 == this->dtnasc.getMes() && ltm->tm_mday < this->dtnasc.getDia())) {
                idade--;
            }
            return idade;
        }
};


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");
	Data *datanasc;

    string email;
    string nome;
    int telefone;
	int diaN;
	int mesN;
	int anoN;

	cout << "Digite seu email: "; 
    cin >> email;
	cout << "Digite seu nome: ";
	cin.ignore();
    getline(cin, nome);
	cout << "Digite o número do seu telefone (sem travessões): "; 
    cin >> telefone;
	cout << "Digite o dia do seu nascimento: "; 
    cin >> diaN;
    cout << "Digite o mês do seu nascimento: "; 
    cin >> mesN;
    cout << "Digite o ano do seu nascimento: "; 
    cin >> anoN; 
    
    datanasc = new Data(diaN, mesN, anoN);
	
	Contato *teste;
	teste = new Contato(email, nome, telefone, *datanasc);
	cout << teste->getContato();
	
	return 0;
}