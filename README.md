# `Projet Game Progamming`

|NOM|PRENOM|MATICULE|
|-------|-----|------|
|BOUKALA BONOKO|FRANCK GABRIEL|25P900|

## **📐 MATH - Bibliothèque de Géométrie 2D**

### **📖 Description du Projet**

**MATH** est une bibliothèque C++ éducative implémentant les concepts fondamentaux de la géométrie 2D à travers des structures de points et de vecteurs. Ce projet démontre l'utilisation des **struct** en C++ pour modéliser des concepts mathématiques.

### **🏗️ Structures et Fonctions**

#### **Structures de Données Simples**

---

```cpp
struct Point2f { float x, y; };    // Point dans l'espace 2D
struct Vector2f { float x, y; };   // Vecteur 2D avec direction et magnitude
```

#### **Fonctions Principales Points 2D**

- **`MakeP2f(x, y)`** - Crée un point aux coordonnées spécifiées
- **`Translate(point, dx, dy)`** - Déplace un point selon un delta
- **`Scale(point, sx, sy)`** - Redimensionne par rapport à l'origine
- **`Scale(point, vector)`** - Redimensionne par rapport à un vecteur
- **`Rotate(point, angle)`** - Rotation autour de l'origine
- **`ToString(point)`** - conversion

#### **Fonctions Principales Vecteurs 2D**

- **`MakeV2f(x, y)`** - Crée un vecteur depuis des composantes
- **`MakeV2f(point1, point2)`** - le vecteur crée par deux points
- **`Add(a, b)`** - Addition vectorielle
- **`Dot(a, b)`** - Produit scalaire
- **`Normalize(v)`** - Normalise un vecteur
- **`Lerp(a, b, t)`** - Interpolation linéaire
- **`Determinant(vecteur1, vecteur2)`** - Calcule distance entre deux vecteurs

---

## **📁 FICHIERS DU PROJET**

### **📄 geometry/point.h**

---

```cpp
#ifndef POINT_H
#define POINT_H

#include <string>

struct Vector2f;

struct Point2f {
    float x;
    float y;
};

Point2f MakeP2f(float x, float y);
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);
Point2f Scale(const Point2f& p, float sx, float sy);
Point2f Scale(const Point2f& p, const Vector2f& s);
Point2f Rotate(const Point2f& p, float angleDegree);

std::string ToString(const Point2f& p);

#endif
```

### **📄 geometry/vector.h**

---

```cpp
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <cmath>

struct Point2f;

struct Vector2f {
    float x;
    float y;
};

// Création de vecteurs
Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);

// Opérations algébriques
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);

// Produits et propriétés
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);
Vector2f Normalize(const Vector2f& v);

// Interpolation et opérations avancées
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);

// Conversion
std::string ToString(const Vector2f& v);

#endif
```

### **📄 geometry/utils.h**

---

```cpp
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Templates pour la conversion en string
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

// Fonction d'affichage variadique
template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    std::cout << ToString(first);
    ((std::cout << ", " << ToString(args)), ...);
    std::cout << std::endl;
}

#endif
```

### **📄 main.cpp** (avec tests unitaires complets)

---

```cpp
#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"
#include <iostream>
#include <cmath>
#include <cassert>

int main() {
    int choix = 0, c = 0, d = 0, k = 0;
    float x, y, a, b, dx, dy, e, f, tx, ty, dot, s, angle, dte, bla;
    Point2f p{0,0}, p2{0,0}, p3{0,0}, dp{0,0}, tp{0,0}, ps{0,0}, ps2{0,0}, r{0,0};
    Vector2f v{0,0}, v2{0,0}, va{0,0}, vs{0,0}, psv{0,0}, n1{0,0}, n2{0,0}, m{0,0};
    std::cout << "====== GEOMETRY DE L'ESPACE =====" << std::endl;
    do{
        std::cout << "1. Creer un point p(x, y);\n"
                  << "2. Creer un vecteur v(x, y);\n"
                  << "3. Creer un vecteur de point v(p1, p2);\n"
                  << "4. Quitter\n"
                  << "Faites un choix : ";
        std::cin >> d;
        switch(d){
            case 1:
                std::cout << "Entrez les coordonnees du point P(x y): ";
                std::cin >> x >> y;
                p = MakeP2f(x, y);
                Print("Point : ", ToString(p));
            break;
            case 2:
                std::cout << "Entrez les coordonnees du vecteur V(x y): ";
                std::cin >> a >> b;
                v = MakeV2f(a, b);
                Print("Vecteur : ", ToString(v));
            break;
            case 3:
                std::cout << "Entrez les coordonnees du vecteur2 V2(x y): ";
                std::cin >> e >> f;
                p2 = MakeP2f(e, f);
                Print("Point2 : ", ToString(p2));
                v2 = MakeV2f(p, p2);
                Print("Vecteur2 : ", ToString(v2));
            break;
            case 4:
                std::cout << "Point et vecteurs crees avec succès✅\n";
            break;
            default:
                std::cout << "Faites un bon choix !!\n";
            break;
        }
    }while(d != 4);


    // ============================================================================
    // 🧪 TESTS DES FONCTIONS - MENUS DES OPERATIONS
    // ============================================================================
 
    std::cout << "\n======================================\n"
              << "        MENU FONCTIONNEL               \n"
              << "======================================\n" << std::endl;
    do{
        std::cout << "1. Translation d'un point;" << std::endl;
        std::cout << "2. Produit scalaire;" << std::endl;
        std::cout << "3. Homotethie d'un point;" << std::endl;
        std::cout << "4. Additon de deux vecteur;" << std::endl;
        std::cout << "5. Soustraction de deux vecteurs;" << std::endl;
        std::cout << "6. Produit scalaire de deux vecteurs;" << std::endl;
        std::cout << "7. Determinant de deux vecteurs;" << std::endl;
        std::cout << "8. Normaliser un vecteur;" << std::endl;
        std::cout << "9. Taille d'un vecteur;" << std::endl;
        std::cout << "10. Interpollation  lineaire;" << std::endl;
        std::cout << "11. Quitter." << std::endl;
        std::cout << "Faitez votre choix :" << std::endl;
        std::cin >> choix;

        switch(choix){
            case 1: // ============== OPERATION DE TRANSLATION =========================
                do{
                    std::cout << "\n1. Translation par des valeurs 'deltas';\n";
                    std::cout << "2. Translation par un vecteur;\n";
                    std::cout << "3. Quitter.\n";
                    std::cout << "Faites votre choix : ";
                    std::cin >> c;
                    switch(c){
                        case 1: // ==================== TRANSLATION AVEC UNE VALEUR (DELTA) ===============
                            std::cout << "Translation par des valeurs 'deltas'.\n"
                                      << "Entrer les valeurs deltas(dx, dy) : ";
                            std::cin >> dx >> dy;
                            dp = Translate(p, dx, dy);
                            Print("Point translaté : ", ToString(dp));
                            std::cout << "" << std::endl;
                        break;
                        case 2: // ================= TRANSLATEUR A L'AIDE D'UN VECTEUR ================
                            std::cout << "Translation par un vecteur : ";
                            p3 = Translate(p, v);
                            Print("Point translaté par un vecteur : ", ToString(p3));
                            std::cout << "" << std::endl;
                        break;
                        case 3:
                            std::cout << "Retour aux operations.\n";
                        break;
                        default:
                            std::cout << "Faites le bon choix !";
                        break;
                    }
                }while(c != 3);
            break;
            case 2: // ================= PRODUIT SCALAIRE ==================
                std::cout << "\n2.Produit scalaire.\n";
                do{
                    std::cout << "1. Produit scalaire entre un point et des valeurs deltas;\n";
                    std::cout << "2. Operation scalaire entre un point et un vecteur;\n";
                    std::cout << "3. Quitter.\n";
                    std::cout << "Faites votre choix : ";
                    std::cin >> k;
                    switch(k){
                        case 1: // ============== PRODUIT SCALAIRE ENTRE UN P1 ET UN P2 ==================
                            std::cout << "Produit scalaire de p et p2 :\n"
                                      << "Entrer les valeurs deltas(dx, dy) : ";
                            std::cin >> tx >> ty;
                            tp = MakeP2f(tx, ty);
                            Print("Point : ", ToString(tp));
                            std::cout << "" << std::endl;
                            ps = Scale(p, tx, ty);
                            Print("Produit scalaire : ", ToString(ps));
                            std::cout << "" << std::endl;
                        break;
                        case 2: // ================= OPERATION SCALAIRE ENTRE UN POINT ET UN VECTEUR ============
                            std::cout << "Operation scalaire entre le point et le vecteur : ";
                            ps2 = Scale(p, v);
                            Print("Point translaté par un vecteur : ", ToString(ps2));
                            std::cout << "" << std::endl;
                        break;
                        case 3:
                            std::cout << "Retour aux operations.\n";
                        break;
                        default:
                            std::cout << "Faites le bon choix !";
                        break;
                    }
                    
                }while(k != 3);
            break;
            case 3: // ================ HOMOTETHIE D'UN POINT ============
                std::cout << "3. Homotethie d'un point\n"
                          << "Entrer l'angle de rotaion : ";
                std::cin >> angle;
                r = Rotate(p, angle);
                Print("Rotation : ", ToString(r));
                std::cout << "" << std::endl;
            break;
            case 4: // ========== ADDITION DE VECTEUR ==================
                std::cout << "4. Addition de vecteur :\n";
                Print("Vecteur1 : ", ToString(v));
                std::cout << "" << std::endl;
                Print("Vecteur2 : ", ToString(v2));
                va = Add(v, v2);
                Print("Vecteur Additif : ", ToString(va));
                std::cout << "" << std::endl;
            break;
            case 5: // =============== SOUSTRACTIOND E VECTEURS ===============
                std::cout << "5. Soustraction de deux vecteurs";
                Print("Vecteur1 : ", ToString(v));
                std::cout << "" << std::endl;
                Print("Vecteur2 : ", ToString(v2));
                vs = Sub(v, v2);
                Print("Vecteur soustrait : ", ToString(vs));
                std::cout << "" << std::endl;
            break;
            case 6: // ================= PRODUIT SCALAIRE DE DEUX VECTEURS ============
                std::cout << "6. Produit scalaire de deux vecteurs\n";
                Print("Vecteur1 : ", ToString(v));
                std::cout << "Entrer une valeur : ";
                std::cin >> s;
                psv = Scale(v, s);
                Print("Produit scalaire (Mise à l'echelle) : ", ToString(psv));
                dot = Dot(v, v2);
                Print("Produit scalaire Dot : ", ToString(dot));
                std::cout << "" << std::endl;
            break;
            case 7: // ================== DETERMINANT DE DEUX VECTEURS ===============
                std::cout << "7. Determinant de deux vecteurs\n";
                Print("Vecteur1 : ", ToString(v));
                std::cout << "" << std::endl;
                Print("Vecteur2 : ", ToString(v2));
                dte = Determinant(v, v2);
                Print("Determinant : ", ToString(dte));
                std::cout << "" << std::endl;
            break;
            case 8: // ================= NORME D'UN VECTEUR ============
                std::cout << "8. Norme d'un vecteur\n";
                Print("Vecteur1 : ", ToString(v));
                n1 = Normalize(v);
                Print("Vecteur normalisé : ", ToString(n1));
                Print("Vecteur2 : ", ToString(v2));
                n2 = Normalize(v2);
                Print("Determinant : ", ToString(n2));
                std::cout << "" << std::endl;
            break;
            case 9:{ // ============= TAILLE D'UN VECTEUR / DISTANCE ENTRE DEUX POINTS ================
                    std::cout << "9. Taille d'un vecteur\n";
                    Print("Vecteur1 : ", ToString(v));
                    float ta1 = Length(v);
                    Print("Taille : ", ToString(ta1));
                    std::cout << "" << std::endl;
                    Print("Vecteur2 : ", ToString(v2));
                    float ta2 = Length(v2);
                    Print("Determinant : ", ToString(ta2));
                break;
            }
            case 10: // ================= INTERPOLLATION LINEAIRE ==================
                    std::cout << "10. Interpollation lineaire.\n"
                            << "Entrer un reel operationel : ";
                    std::cin >> bla;
                    m = Lerp(v, v2, bla);
                    Print("Interpollation : ", ToString(bla));
                break;
            case 11:
                std::cout << "Merci pour votre confiance.\n";
            break;
            default:
                std::cout << "Fais un bon choix !";
            break;
        }
    }while(choix != 11);

    std::cout << "\n=========================================\n"
              << "           🏁 TESTS TERMINÉS"
              << "\n=========================================";
    return 0;
}
```

---

```bash
chcp 65001
g++ main.cpp geometry/*.cpp -I geometry -o geometry.exe
./geometry.exe
```

---

## **💡 Ce qu'il faut Retenir**

### **Avantages des Struct sur les Classes**

- **Données publiques** par défaut - accès direct aux coordonnées
- **Sémantique de valeur** - copie simple et prédictible
- **Compatibilité C** - interopérabilité avec d'autres langages
- **Overhead minimal** - pas de coût d'abstraction

### **Concepts Mathématiques Maîtrisés**

- **Algèbre linéaire** 2D appliquée
- **Transformations géométriques** (translation, rotation, produit scalaire)
- **Calcul vectoriel** (produit scalaire, normalisation)
- **Interpolation** et transitions

## **🎓 Ce qu'on Apprend en Réalisant ce Projet**

### **Développement avec Struct**

- Organisation de code sans Programmation Orientée Objet
- Fonctions pures sans état
- Gestion de la précision numérique
- Tests unitaires complets

### **Compétences Générales**

- Pensée algorithmique géométrique
- Débogage mathématique
- Validation rigoureuse par tests
- Documentation de code

---

**🎯 Fin du Projet MATH**  

*"Maîtriser les fondations pour construire l'avenir"* 🚀

