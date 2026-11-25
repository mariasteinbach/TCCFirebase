#include <iostream>
using namespace std;
#include <queue>

int main(){

//1 
queue<string> fila;
fila.push("Ana");
    fila.push("Paulo");
    fila.push("Camila");
    fila.push("Edna");
    fila.push("Wanderleia");
    while (!fila.empty()) {
        cout << "Atendendo: " << fila.front() << endl;
        fila.pop();
        cout << "Clientes restantes: " << fila.size() << endl;
    }
    cout << "Todos os clientes foram atendidos!" << endl;
//2
queue<string> filaMercado;
    int opcao;
    string nome;
    do {
        cout << "1 - Adicionar cliente" << endl;
        cout << "2 - Atender proximo cliente" << endl;
        cout << "3 - Mostrar quantos estao esperando" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Nome do cliente: ";
            cin >> nome;
            filaMercado.push(nome);
            cout << nome << " entrou na fila." << endl;
        }
        else if (opcao == 2) {
            if (!filaMercado.empty()) {
                cout << "Atendendo: " << filaMercado.front() << endl;
                filaMercado.pop();
            } else {
                cout << "Nao ha clientes na fila." << endl;
            }
        }
        else if (opcao == 3) {
            cout << "Pessoas esperando: " << filaMercado.size() << endl;
        }
        else if (opcao == 0) {
            cout << "Encerrando o programa..." << endl;
        }
        else {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);
//3
queue<string> filaC;
filaC.push("Alana");
    filaC.push("Alice");
    filaC.push("Amanda");
    filaC.push("Ana");
    filaC.push("Antonella");
    cout << "Atendendo: " << filaC.front() << endl;
    filaC.pop();
    cout << "Atendendo: " << filaC.front() << endl;
    filaC.pop();
    cout << "Alunos ainda esperando: " << filaC.size() << endl;
//4
queue<string> filaRestaurante;
filaRestaurante.push("Familia Yoki");
    filaRestaurante.push("Tio Paulo");
    filaRestaurante.push("Dona Elize");
    filaRestaurante.push("Casal Marcos e Náthalia");
    filaRestaurante.push("Grupo de amigos");
    filaRestaurante.push("Sr. Afonso");

    int mesasLivres = 5;

    while (!filaRestaurante.empty() && mesasLivres > 0) {
        cout << "Mesa disponivel! Chamando: " << filaRestaurante.front() << endl;
        filaRestaurante.pop();
        mesasLivres--;
        cout << "Mesas livres agora: " << mesasLivres << endl;
    }

    if (mesasLivres == 0) {
        cout << "Todas as mesas estao ocupadas." << endl;
    }
    if (!filaRestaurante.empty()) {
        cout << "Ainda esperando: " << filaRestaurante.size() << " cliente(s)." << endl;
    }
//5
queue<string> filaPacientes;
filaPacientes.push("Ana");
filaPacientes.push("Bruno");
filaPacientes.push("Carla");
filaPacientes.push("Daniel");
cout << "Proximo paciente: " << filaPacientes.front() << endl;
while (!filaPacientes.empty()) {
        cout << "Atendendo paciente: " << filaPacientes.front() << endl;
        filaPacientes.pop();
    }

    cout << "Todos os pacientes foram atendidos." << endl;
//6
queue<string> filaImprimir;
filaImprimir.push("prova.docx");
filaImprimir.push("fototurma.png");
filaImprimir.push("provaparana.txt");
filaImprimir.push("aulasEdFisica.pdf");
while (!filaImprimir.empty()) {
        cout << "Imprimindo: " << filaImprimir.front() << endl;
        filaImprimir.pop();
    }

    cout << "Todos os documentos foram impressos." << endl;
//7
queue<string> filaOnibus;
filaOnibus.push("Ivanir");
    filaOnibus.push("Alberto");
    filaOnibus.push("Caique");
    filaOnibus.push("Emanuelly");
    filaOnibus.push("Edvaldo");
    while (!filaOnibus.empty()) {
        cout << "Embarrando: " << filaOnibus.front() << endl;
        filaOnibus.pop();
    }

    cout << "Todos embarcaram." << endl;
//8
queue<string> filaCinema;
    int opcao;
    string nome;

    do {
        cout << "1 - Adicionar pessoa" << endl;
        cout << "2 - Atender a primeira pessoa" << endl;
        cout << "3 - Mostrar o proximo" << endl;
        cout << "4 - Mostrar quantos estao esperando" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Nome: ";
            cin >> nome;
            filaCinema.push(nome);
            cout << nome << " entrou na fila." << endl;
        }
        else if (opcao == 2) {
            if (!filaCinema.empty()) {
                cout << "Atendendo: " << filaCinema.front() << endl;
                filaCinema.pop();
            } else {
                cout << "Fila vazia." << endl;
            }
        }
        else if (opcao == 3) {
            if (!filaCinema.empty()) {
                cout << "Proximo: " << filaCinema.front() << endl;
            } else {
                cout << "Fila vazia." << endl;
            }
        }
        else if (opcao == 4) {
            cout << "Pessoas esperando: " << filaCinema.size() << endl;
        }
        else if (opcao == 0) {
            cout << "Encerrando..." << endl;
        }
        else {
            cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);


return 0;
}