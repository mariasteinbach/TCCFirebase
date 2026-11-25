import tkinter as tk
from tkinter import ttk, messagebox
import database

def listar_emprestimos():
    for item in tabela.get_children():
        tabela.delete(item)
    emprestimos = database.listar_emprestimos()
    for emp in emprestimos:
        tabela.insert("", tk.END, values=emp)

def limpar_campos():
    entrada_leitor.delete(0, tk.END)
    entrada_titulo.delete(0, tk.END)
    entrada_autor.delete(0, tk.END)
    entrada_data_emp.delete(0, tk.END)
    entrada_data_dev.delete(0, tk.END)
    combo_status.set("Emprestado")
    tabela.selection_remove(tabela.selection())

def cadastrar_emprestimo():
    nome_leitor = entrada_leitor.get().strip()
    titulo_livro = entrada_titulo.get().strip()
    autor_livro = entrada_autor.get().strip()
    data_emprestimo = entrada_data_emp.get().strip()
    data_devolucao = entrada_data_dev.get().strip()
    status = combo_status.get()

    if not nome_leitor or not titulo_livro or not autor_livro \
       or not data_emprestimo or not data_devolucao:
        messagebox.showerror("Erro", "Todos os campos devem ser preenchidos.")
        return

    database.cadastrar_emprestimo(nome_leitor, titulo_livro, autor_livro,
                                  data_emprestimo, data_devolucao, status)
    limpar_campos()
    listar_emprestimos()

def selecionar_emprestimo(event):
    item_selecionado = tabela.selection()
    if not item_selecionado:
        return
    dados = tabela.item(item_selecionado[0], 'values')
    entrada_leitor.delete(0, tk.END)
    entrada_leitor.insert(0, dados[1])
    entrada_titulo.delete(0, tk.END)
    entrada_titulo.insert(0, dados[2])
    entrada_autor.delete(0, tk.END)
    entrada_autor.insert(0, dados[3])
    entrada_data_emp.delete(0, tk.END)
    entrada_data_emp.insert(0, dados[4])
    entrada_data_dev.delete(0, tk.END)
    entrada_data_dev.insert(0, dados[5])
    combo_status.set(dados[6])

def atualizar_emprestimo():
    item_selecionado = tabela.selection()
    if not item_selecionado:
        messagebox.showerror("Erro", "Selecione um empréstimo para atualizar.")
        return

    id_emp = tabela.item(item_selecionado[0], 'values')[0]
    nome_leitor = entrada_leitor.get().strip()
    titulo_livro = entrada_titulo.get().strip()
    autor_livro = entrada_autor.get().strip()
    data_emprestimo = entrada_data_emp.get().strip()
    data_devolucao = entrada_data_dev.get().strip()
    status = combo_status.get()

    if not nome_leitor or not titulo_livro or not autor_livro \
       or not data_emprestimo or not data_devolucao:
        messagebox.showerror("Erro", "Todos os campos devem ser preenchidos.")
        return

    database.atualizar_emprestimo(id_emp, nome_leitor, titulo_livro, autor_livro,
                                  data_emprestimo, data_devolucao, status)
    limpar_campos()
    listar_emprestimos()

def excluir_emprestimo():
    item_selecionado = tabela.selection()
    if not item_selecionado:
        messagebox.showerror("Erro", "Selecione um empréstimo para excluir.")
        return
    id_emp = tabela.item(item_selecionado[0], 'values')[0]
    database.excluir_emprestimo(id_emp)
    limpar_campos()
    listar_emprestimos()

# ---------- JANELA ----------
janela = tk.Tk()
janela.title("Empréstimo de Livros - Biblioteca")
janela.geometry("900x500")

tk.Label(janela, text="Nome do Leitor:").grid(row=0, column=0, padx=5, pady=5, sticky="e")
entrada_leitor = tk.Entry(janela, width=30)
entrada_leitor.grid(row=0, column=1, padx=5, pady=5)

tk.Label(janela, text="Título do Livro:").grid(row=1, column=0, padx=5, pady=5, sticky="e")
entrada_titulo = tk.Entry(janela, width=30)
entrada_titulo.grid(row=1, column=1, padx=5, pady=5)

tk.Label(janela, text="Autor do Livro:").grid(row=2, column=0, padx=5, pady=5, sticky="e")
entrada_autor = tk.Entry(janela, width=30)
entrada_autor.grid(row=2, column=1, padx=5, pady=5)

tk.Label(janela, text="Data Empréstimo (DD/MM/AAAA):").grid(row=3, column=0, padx=5, pady=5, sticky="e")
entrada_data_emp = tk.Entry(janela, width=30)
entrada_data_emp.grid(row=3, column=1, padx=5, pady=5)

tk.Label(janela, text="Data Devolução (DD/MM/AAAA):").grid(row=4, column=0, padx=5, pady=5, sticky="e")
entrada_data_dev = tk.Entry(janela, width=30)
entrada_data_dev.grid(row=4, column=1, padx=5, pady=5)

tk.Label(janela, text="Status:").grid(row=5, column=0, padx=5, pady=5, sticky="e")
combo_status = ttk.Combobox(janela, values=["Emprestado", "Devolvido"], width=27, state="readonly")
combo_status.set("Emprestado")
combo_status.grid(row=5, column=1, padx=5, pady=5)

frame_botoes = tk.Frame(janela)
frame_botoes.grid(row=6, column=0, columnspan=2, pady=10)

tk.Button(frame_botoes, text="Cadastrar", command=cadastrar_emprestimo).pack(side=tk.LEFT, padx=5)
tk.Button(frame_botoes, text="Atualizar", command=atualizar_emprestimo).pack(side=tk.LEFT, padx=5)
tk.Button(frame_botoes, text="Excluir", command=excluir_emprestimo).pack(side=tk.LEFT, padx=5)
tk.Button(frame_botoes, text="Limpar Campos", command=limpar_campos).pack(side=tk.LEFT, padx=5)

colunas = ("ID", "Leitor", "Título", "Autor", "Empréstimo", "Devolução", "Status")
tabela = ttk.Treeview(janela, columns=colunas, show="headings")

tabela.heading("ID", text="ID")
tabela.heading("Leitor", text="Leitor")
tabela.heading("Título", text="Título")
tabela.heading("Autor", text="Autor")
tabela.heading("Empréstimo", text="Empréstimo")
tabela.heading("Devolução", text="Devolução")
tabela.heading("Status", text="Status")

tabela.column("ID", width=50, anchor=tk.CENTER)
tabela.column("Leitor", width=150, anchor=tk.W)
tabela.column("Título", width=150, anchor=tk.W)
tabela.column("Autor", width=120, anchor=tk.W)
tabela.column("Empréstimo", width=100, anchor=tk.CENTER)
tabela.column("Devolução", width=100, anchor=tk.CENTER)
tabela.column("Status", width=100, anchor=tk.CENTER)

tabela.grid(row=7, column=0, columnspan=2, padx=10, pady=10)

tabela.bind("<<TreeviewSelect>>", selecionar_emprestimo)

database.criar_tabela()
listar_emprestimos()

janela.mainloop()