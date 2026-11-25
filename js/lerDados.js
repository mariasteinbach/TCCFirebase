import { db } from "./script.js";
import {
  collection,
  query,
  orderBy,
  onSnapshot
} from "https://www.gstatic.com/firebasejs/10.12.2/firebase-firestore.js";

const tabelaCorpo = document.getElementById("tabelaProdutos");

function escapeHtml(texto) {
  const div = document.createElement("div");
  div.textContent = texto ?? "";
  return div.innerHTML;
}

function formatarDataBR(dataIso) {
  if (!dataIso) return "-";
  const partes = dataIso.split("-");
  if (partes.length !== 3) return escapeHtml(dataIso);
  return `${partes[2]}/${partes[1]}/${partes[0]}`;
}

const consulta = query(collection(db, "emprestimos"), orderBy("criadoEm", "desc"));

onSnapshot(
  consulta,
  (snapshot) => {
    tabelaCorpo.innerHTML = "";

    if (snapshot.empty) {
      tabelaCorpo.innerHTML = `
      <tr>
        <td colspan="6" class="text-center text-muted">Nenhum empréstimo registrado.</td>
      </tr>`;
      return;
    }

    snapshot.forEach((doc) => {
      const emprestimo = doc.data();
      const linha = document.createElement("tr");

      linha.innerHTML = `
        <td>${escapeHtml(emprestimo.titulo)}</td>
        <td>${escapeHtml(emprestimo.autor)}</td>
        <td>${formatarDataBR(emprestimo.dataEmprestimo)}</td>
        <td><span class="badge ${emprestimo.formato === 'PDF' ? 'bg-danger' : 'bg-info'}">${escapeHtml(emprestimo.formato)}</span></td>
        <td>${escapeHtml(emprestimo.nomeLeitor)}</td>
        <td>${escapeHtml(emprestimo.telefoneLeitor)}</td>
      `;

      tabelaCorpo.appendChild(linha);
    });
  },
  (erro) => {
    console.error("Erro ao ler dados:", erro);
    tabelaCorpo.innerHTML = `
    <tr>
      <td colspan="6" class="text-center text-danger">Erro ao carregar os dados.</td>
    </tr>`;
  }
);