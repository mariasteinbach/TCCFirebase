import { db } from "./script.js";
import {
  collection,
  addDoc,
  serverTimestamp
} from "https://www.gstatic.com/firebasejs/10.12.2/firebase-firestore.js";

const form = document.getElementById("contactForm");

form.addEventListener("submit", async (evento) => {
  evento.preventDefault();

  const titulo = document.getElementById("titulo").value;
  const autor = document.getElementById("autor").value;
  const dataEmprestimo = document.getElementById("dataEmprestimo").value;
  const formato = document.getElementById("formato").value;
  const nomeLeitor = document.getElementById("nomeLeitor").value;
  const telefoneLeitor = document.getElementById("telefoneLeitor").value;

  try {
    const docRef = await addDoc(collection(db, "emprestimos"), {
      titulo: titulo,
      autor: autor,
      dataEmprestimo: dataEmprestimo,
      formato: formato,
      nomeLeitor: nomeLeitor,
      telefoneLeitor: telefoneLeitor,
      criadoEm: serverTimestamp()
    });

    console.log("Empréstimo registrado com ID:", docRef.id);
    alert("Empréstimo registrado com sucesso!");
    form.reset();
  } catch (erro) {
    console.error("Erro ao registrar empréstimo:", erro);
    alert("Erro ao enviar os dados. Veja o console.");
  }
});