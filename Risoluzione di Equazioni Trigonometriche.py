import sympy as sp

def risolvi_equazione_trigonometica(equazione, variabile):
    soluzioni = sp.solve(equazione, variabile)
    return soluzioni

# Esempio di utilizzo
x = sp.symbols('x')
equazione = sp.sin(x) - 0.5
soluzioni = risolvi_equazione_trigonometica(equazione, x)

print("Le soluzioni dell'equazione sono:", soluzioni)
