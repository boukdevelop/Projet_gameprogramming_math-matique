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