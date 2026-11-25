import sqlite3

def criar_tabela():
    conexao = sqlite3.connect('biblioteca.db')
    cursor = conexao.cursor()

    cursor.execute('''
    CREATE TABLE IF NOT EXISTS emprestimos (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        nome_leitor TEXT NOT NULL,
        titulo_livro TEXT NOT NULL,
        autor_livro TEXT NOT NULL,
        data_emprestimo TEXT NOT NULL,
        data_devolucao TEXT NOT NULL,
        status TEXT NOT NULL
    )
    ''')

    conexao.commit()
    conexao.close()

# Cadastrar Empréstimo
def cadastrar_emprestimo(nome_leitor, titulo_livro, autor_livro,
                         data_emprestimo, data_devolucao, status):
    conexao = sqlite3.connect('biblioteca.db')
    cursor = conexao.cursor()

    cursor.execute('''
    INSERT INTO emprestimos
    (nome_leitor, titulo_livro, autor_livro, data_emprestimo, data_devolucao, status)
    VALUES (?, ?, ?, ?, ?, ?)
    ''', (nome_leitor, titulo_livro, autor_livro,
          data_emprestimo, data_devolucao, status))

    conexao.commit()
    conexao.close()

# Listar Empréstimos
def listar_emprestimos():
    conexao = sqlite3.connect('biblioteca.db')
    cursor = conexao.cursor()

    cursor.execute('SELECT * FROM emprestimos')
    emprestimos = cursor.fetchall()

    conexao.close()
    return emprestimos

# Atualizar Empréstimo
def atualizar_emprestimo(id, nome_leitor, titulo_livro, autor_livro,
                         data_emprestimo, data_devolucao, status):
    conexao = sqlite3.connect('biblioteca.db')
    cursor = conexao.cursor()

    cursor.execute('''
    UPDATE emprestimos
    SET nome_leitor = ?, titulo_livro = ?, autor_livro = ?,
        data_emprestimo = ?, data_devolucao = ?, status = ?
    WHERE id = ?
    ''', (nome_leitor, titulo_livro, autor_livro,
          data_emprestimo, data_devolucao, status, id))

    conexao.commit()
    conexao.close()

# Excluir Empréstimo
def excluir_emprestimo(id):
    conexao = sqlite3.connect('biblioteca.db')
    cursor = conexao.cursor()

    cursor.execute('DELETE FROM emprestimos WHERE id = ?', (id,))

    conexao.commit()
    conexao.close()