import { initializeApp } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-app.js";
import { getFirestore } from "https://www.gstatic.com/firebasejs/10.12.2/firebase-firestore.js";

const firebaseConfig = {
  apiKey: "AIzaSyDQkF1Ii93QyhaC6C1fEkxwkeODm9sjjKk",
  authDomain: "atividadedebanco.firebaseapp.com",
  projectId: "atividadedebanco",
  storageBucket: "atividadedebanco.firebasestorage.app",
  messagingSenderId: "376921128777",
  appId: "1:376921128777:web:0ccd985e6ea23aed27e498"
};

const app = initializeApp(firebaseConfig);
export const db = getFirestore(app);