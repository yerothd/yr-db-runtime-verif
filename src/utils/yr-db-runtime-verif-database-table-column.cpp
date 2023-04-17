/*
 * yr-db-runtime-verif-database-table-column.cpp
 *
 *      Author: DIPL.-INF. XAVIER NOUMBISSI NOUNDOU
 */

#include "yr-db-runtime-verif-database-table-column.hpp"


const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::IS_SERVICE("is_service");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
IS_VENTE_EN_GROS("is_vente_en_gros");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::ID_ALERTE("id_alerte");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::ID("id");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
HISTORIQUE_STOCK("historique_stock");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::CLIENTS_ID("clients_id");

const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REFERENCE_RECU_PAIEMENT_CLIENT("reference_recu_paiement_client");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REFERENCE_RECU_VENDU("reference_recu_vendu");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REFERENCE_RECU_SORTIE("reference_recu_sortie");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
ENREGISTREUR_STOCK("enregistreur_stock");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::REFERENCE("reference");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
COMPTE_FOURNISSEUR("compte_fournisseur");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::COMPTE_CLIENT("compte_client");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DETTE_MAXIMALE_COMPTE_CLIENT("dette_maximale_compte_client");

const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::CATEGORIE("categorie");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::QUANTITE("quantite");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::STOCK_DALERTE("stock_dalerte");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::STOCK_MINIMUM("stock_minimum");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::STOCK_MAXIMUM("stock_maximum");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::QUANTITE_VENDUE("quantite_vendue");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::QUANTITE_TOTALE("quantite_totale");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::QUANTITE_SORTIE("quantite_sortie");

const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DESCRIPTION_FOURNISSEUR("description_fournisseur");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DESCRIPTION_PRODUIT("description_produit");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PRIX_UNITAIRE("prix_unitaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
PRIX_UNITAIRE_EN_GROS("prix_unitaire_en_gros");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REFERENCE_RECU_DACHAT("reference_recu_dachat");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
PRIX_DACHAT_PRECEDENT("prix_dachat_precedent");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PRIX_DACHAT("prix_dachat");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
PRIX_VENTE_PRECEDENT("prix_vente_precedent");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PRIX_VENTE_EN_GROS_PRECEDENT
("prix_vente_en_gros_precedent");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PRIX_VENTE("prix_vente");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
PRIX_VENTE_EN_GROS("prix_vente_en_gros");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::REFERENCE_DU_COMPTE_BANCAIRE
("reference_du_compte_bancaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::AGENCE_DU_COMPTE_BANCAIRE
("agence_du_compte_bancaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::INTITULE_DU_COMPTE_BANCAIRE
("intitule_du_compte_bancaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
INSTITUT_BANCAIRE("institut_bancaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DESCRIPTION_DU_COMPTE_BANCAIRE
("description_du_compte_bancaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DESCRIPTION_CATEGORIE("description_categorie");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_CATEGORIE("nom_categorie");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::MONTANT_TVA("montant_tva");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
MONTANT_TVA_EN_GROS("montant_tva_en_gros");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::TVA("tva");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
MARGE_BENEFICIAIRE("marge_beneficiaire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::MARGE_BENEFICIAIRE_EN_GROS
("marge_beneficiaire_en_gros");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::MONTANT_RECU("montant_recu");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
MONTANT_A_REMBOURSER("montant_a_rembourser");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
MONTANT_TOTAL_VENTE("montant_total_vente");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::REMISE_PRIX("remise_prix");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REMISE_POURCENTAGE("remise_pourcentage");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::LOCALISATION("localisation");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
LOCALISATION_STOCK("localisation_stock");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
QUANTITE_PAR_LOT("quantite_par_lot");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::LOTS_ENTRANT("lots_entrant");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
IMAGE_FOURNISSEUR("image_fournisseur");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
IMAGE_COMPTE_CLIENT("image_compte_client");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::IMAGE_PRODUIT("image_produit");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_PEREMPTION("date_peremption");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DATE_DE_RECEPTION("date_de_reception");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DATE_DE_COMMANDE("date_de_commande");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_ENTREE("date_entree");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PRENOM("prenom");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM("nom");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_RECEPTEUR("nom_recepteur");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_MAGASINIER("nom_magasinier");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_UTILISATEUR_MAGASINIER
("nom_utilisateur_magasinier");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_UTILISATEUR_CAISSIER
("nom_utilisateur_caissier");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_CAISSIER("nom_caissier");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_COMPLET_CREATEUR_REMISE_ALERTE
("nom_complet_createur_remise_alerte");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_COMPLET("nom_complet");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
NOM_LOCALISATION("nom_localisation");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_UTILISATEUR("nom_utilisateur");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::STOCKS_ID("stocks_id");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::STOCK_MANAGER("stock_manager");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::MOT_PASSE("mot_passe");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::TITRE("titre");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
APPELATION_TITRE("appelation_titre");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::ROLE("role");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_ROLE("nom_role");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::EMAIL("email");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REFERENCE_FOURNISSEUR("reference_fournisseur");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
REFERENCE_CLIENT("reference_client");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
NUMERO_TELEPHONE_1("numero_telephone_1");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
NUMERO_TELEPHONE_2("numero_telephone_2");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::LIEU_NAISSANCE("lieu_naissance");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_NAISSANCE("date_naissance");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::VILLE("ville");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::QUARTIER("quartier");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PROVINCE_ETAT("province_etat");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::PAYS("pays");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::ADRESSE("adresse");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::ADRESSE_IP("adresse_ip");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::BOITE_POSTALE("boite_postale");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::STATUT_RESOLU("statut_resolu");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::SIEGE_SOCIAL("siege_social");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOTES("notes");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_ENTREPRISE("nom_entreprise");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
SECTEURS_DACTIVITES("secteurs_dactivites");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::REFERENCE_REGISTRE_DU_COMMERCE
("reference_registre_du_commerce");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
NUMERO_CONTRIBUABLE("numero_contribuable");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
NOM_REPRESENTANT("nom_representant");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
NOM_ENTREPRISE_CLIENT("nom_entreprise_client");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_ENTREPRISE_FOURNISSEUR
("nom_entreprise_fournisseur");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DESCRIPTION_CLIENT("description_client");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DESIGNATION("designation");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DESIGNATION_REMISE("designation_remise");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
DESIGNATION_ALERTE("designation_alerte");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
CONDITION_ALERTE("condition_alerte");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_ENCAISSEUR("nom_encaisseur");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_PAIEMENT("date_paiement");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::MONTANT_PAYE("montant_paye");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_VENTE("date_vente");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_DEBUT("date_debut");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_FIN("date_fin");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_SORTIE("date_sortie");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::HEURE_PAIEMENT("heure_paiement");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::HEURE_VENTE("heure_vente");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::HEURE_SORTIE("heure_sortie");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DESTINATAIRE("destinataire");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOM_COMPLET_DESTINATAIRE
("nom_complet_destinataire");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::REMISE_NOTES("remise_notes");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::MESSAGE_ALERTE("message_alerte");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::DATE_CREATION("date_creation");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
TYPE_DE_PAIEMENT("type_de_paiement");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::TYPE_DE_VENTE("type_de_vente");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::NOTIFICATIONS("notifications");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::REMISE_RESOLUE("remise_resolue");
const QString YR_DB_RUNTIME_VERIF_DatabaseTableColumn::ALERTE_RESOLUE("alerte_resolue");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
LOCALISATION_SORTIE("localisation_sortie");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
LOCALISATION_ENTREE("localisation_entree");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
LOCALISATION_SORTIE_ID("localisation_sortie_id");
const QString
YR_DB_RUNTIME_VERIF_DatabaseTableColumn::
LOCALISATION_ENTREE_ID("localisation_entree_id");
