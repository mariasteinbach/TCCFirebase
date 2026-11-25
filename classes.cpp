#include <iostream>
using namespace std;

class Produto {
public:
    string nome;
    string barCode;
    double preco;
    int qtd;
    string categoria;

    void exibirProduto() {
        cout << "Nome: " << nome << endl;
        cout << "BarCode: " << barCode << endl;
        cout << "Preço: " << preco << endl;
        cout << "Quantidade: " << qtd << endl;
        cout << "Categoria: " << categoria << endl;
    }

    void atualizarPreco(double novoPreco) {
        preco = novoPreco;
    }

    void vender(int quantidade) {
        if (quantidade <= qtd) {
            qtd -= quantidade;
            cout << "Venda realizada! Estoque restante: " << qtd << endl;
        } else {
            cout << "Estoque insuficiente!" << endl;
        }
    }
};  
class Perfil {         
public:
    string username;
    string bio;
    int seguidores;
    int seguindo;
    bool verificado;

    void exibirPerfil() {
        cout << "Username: " << username << endl;
        cout << "Bio: " << bio << endl;
        cout << "Seguidores: " << seguidores << endl;
        cout << "Seguindo: " << seguindo << endl;
        cout << "Verificado: " << (verificado ? "Sim" : "Nao") << endl;
    }

    void ganharSeguidor() {
        seguidores++;
    }

    void editarBiografia(string novaBio) {
        bio = novaBio;
    }
};

class Conta {
public:
    string titular;
    int numero;
    double saldo;
    double limite;

    void verSaldo() {
        cout << "Saldo: " << saldo << " | Limite: " << limite
             << " | Disponivel: " << (saldo + limite) << endl;
    }

    void depositar(double valor) {
        saldo += valor;
    }

    void sacar(double valor) {
        if (valor <= saldo + limite) {
            saldo -= valor;
            cout << "Saque de " << valor << " realizado!" << endl;
        } else {
            cout << "Saldo + limite insuficiente!" << endl;
        }
    }
};

class Carro {
public:
    string marca;
    string modelo;
    int ano;
    double quilometragem;
    double diaria;

    void exibirFichaTecnica() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Ano: " << ano << endl;
        cout << "Km: " << quilometragem << endl;
        cout << "Diaria: " << diaria << endl;
    }

    void viajar(double distancia) {
        quilometragem += distancia;
    }

    double calcularAluguel(int dias) {
        return dias * diaria;
    }
};

class Livro {
public:
    string titulo;
    string autor;
    int paginas;
    double preco;
    bool emprestado;

    void mostrarInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Paginas: " << paginas << endl;
        cout << "Preco: " << preco << endl;
        cout << "Status: " << (emprestado ? "Emprestado" : "Disponivel") << endl;
    }

    void emprestar() {
        if (!emprestado) {
            emprestado = true;
            cout << "Livro emprestado!" << endl;
        } else {
            cout << "Livro ja esta emprestado!" << endl;
        }
    }

    void devolver() {
        emprestado = false;
        cout << "Livro devolvido!" << endl;
    }
};

class Smartphone {
public:
    string marca;
    string modelo;
    int armazenamento;
    int ram;
    int bateria;

    void especificacoes() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Armazenamento: " << armazenamento << " GB" << endl;
        cout << "RAM: " << ram << " GB" << endl;
        cout << "Bateria: " << bateria << "%" << endl;
    }

    void jogar(int horas) {
        bateria -= horas * 15;
        if (bateria < 0) bateria = 0;
        cout << "Bateria agora: " << bateria << "%" << endl;
    }

    void carregar(int porcentagem) {
        bateria += porcentagem;
        if (bateria > 100) bateria = 100;
        cout << "Bateria agora: " << bateria << "%" << endl;
    }
};

class ItemCardapio {
public:
    string nomePrato;
    double preco;
    int tempoPreparo;
    int calorias;
    bool vegetariano;

    void exibirItem() {
        cout << "Prato: " << nomePrato << endl;
        cout << "Preco: " << preco << endl;
        cout << "Tempo de preparo: " << tempoPreparo << " min" << endl;
        cout << "Calorias: " << calorias << endl;
        if (vegetariano) {
            cout << "*** PRATO VEGETARIANO ***" << endl;
        } else {
            cout << "Prato com carne" << endl;
        }
    }

    void aplicarDesconto(double porcentagem) {
        preco = preco - (preco * porcentagem / 100);
        cout << "Novo preco: " << preco << endl;
    }

    void alterarTempoPreparo(int novoTempo) {
        tempoPreparo = novoTempo;
    }
};

int main() {
    //1
    Produto arroz, leite;
    arroz.nome = "Arroz Prato Fino";
    arroz.barCode = "1234";
    arroz.preco = 28.9;
    arroz.qtd = 10;
    arroz.categoria = "Alimento não perecível";
    leite.nome = "Leite Líder";
    leite.barCode = "4321";
    leite.preco = 15.99;
    leite.qtd = 8;
    leite.categoria = "Laticínio";
    arroz.exibirProduto();
    arroz.atualizarPreco(30.0);
    arroz.vender(3);
    cout << "---" << endl;
    leite.exibirProduto();
    //2
    Perfil influenciador, pessoal, marca;
    influenciador.username = "@famoso";
    influenciador.bio = "Influenciador digital";
    influenciador.seguidores = 1000000;
    influenciador.seguindo = 300;
    influenciador.verificado = true;
    influenciador.exibirPerfil();
    influenciador.ganharSeguidor();
    influenciador.editarBiografia("Novo bio top");
    cout << "---" << endl;
    influenciador.exibirPerfil();
    //3
    Conta joao, maria, pedro;
    joao.titular = "Joao";
    joao.numero = 1001;
    joao.saldo = 500.0;
    joao.limite = 200.0;
    joao.verSaldo();
    joao.depositar(150.0);
    joao.sacar(700.0);
    joao.verSaldo();
    //4
    Carro sedan, esportivo, suv;
    sedan.marca = "Toyota";
    sedan.modelo = "Corolla";
    sedan.ano = 2022;
    sedan.quilometragem = 15000;
    sedan.diaria = 200.0;
    sedan.exibirFichaTecnica();
    sedan.viajar(120.5);
    cout << "Aluguel 3 dias: " << sedan.calcularAluguel(3) << endl;
    //5
    Livro fantasia, ficcao, biografia;
    fantasia.titulo = "O Senhor dos Aneis";
    fantasia.autor = "Tolkien";
    fantasia.paginas = 1200;
    fantasia.preco = 89.9;
    fantasia.emprestado = false;
    fantasia.mostrarInfo();
    fantasia.emprestar();
    fantasia.emprestar(); 
    fantasia.devolver();
    //6
    Smartphone premium, intermediario, basico;
    premium.marca = "Samsung";
    premium.modelo = "Galaxy S24 Ultra";
    premium.armazenamento = 512;
    premium.ram = 12;
    premium.bateria = 80;
    premium.especificacoes();
    premium.jogar(2);
    premium.carregar(50);
    //7
    ItemCardapio hamburguer, salada, pizza, batata;
    hamburguer.nomePrato = "Hamburguer Artesanal";
    hamburguer.preco = 35.0;
    hamburguer.tempoPreparo = 20;
    hamburguer.calorias = 850;
    hamburguer.vegetariano = false;
    salada.nomePrato = "Salada Caesar";
    salada.preco = 25.0;
    salada.tempoPreparo = 10;
    salada.calorias = 300;
    salada.vegetariano = true;
    pizza.nomePrato = "Pizza Margherita";
    pizza.preco = 45.0;
    pizza.tempoPreparo = 25;
    pizza.calorias = 700;
    pizza.vegetariano = true;
    batata.nomePrato = "Batata Frita";
    batata.preco = 18.0;
    batata.tempoPreparo = 12;
    batata.calorias = 400;
    batata.vegetariano = true;
    hamburguer.exibirItem();
    cout << "---" << endl;
    salada.exibirItem();
    cout << "---" << endl;
    pizza.exibirItem();
    pizza.aplicarDesconto(10);
    pizza.alterarTempoPreparo(20);
    cout << "---" << endl;
    batata.exibirItem();
    
return 0;
}