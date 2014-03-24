#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <sstream>
#include <QString>
#include <QWidget>
#include <QtDebug>

#include "LDAPConnection.h"

/**
 * Base d'annuaire
 */
#define BASEDN "dc=GarmirKatch,dc=fr"

/**
 * Permissions autorisees
 */
#define A_FIELD_READ   "aFieldRead"
#define A_FIELD_WRITE  "aFieldWrite"
#define A_TABLE_ADD    "aTableAdd"
#define A_TABLE_DELETE "aTableDel"

/**
 * Permissions refusees
 */
#define R_FIELD_READ   "rFieldRead"
#define R_FIELD_WRITE  "rFieldWrite"
#define R_TABLE_ADD    "rTableAdd"
#define R_TABLE_DELETE "rTableDel"

class Directory : public QWidget {

	Q_OBJECT

public:

	explicit Directory(QWidget* parent = 0);
	virtual ~Directory();

	/**
	 * @brief Directory
	 * @param hostname adresse de l'annuaire
	 * @param port le port pour la connection
	 */
	bool initialize(const QString& hostname = "localhost", const int port = 389);

	/**
	 * @brief authentification confirmation de la connection client
	 * @param uid le login
	 * @param pwd le mot de passe
	 * @return true si on est connecté, false sinon
	 */
	bool authentification(const QString& uid, const QString& pwd);

	/**
	 * @brief canRead retourne true si le login uid a droit de lire une colonne d'une table
	 * @param uid       le login
	 * @param tableName la table
	 * @param fieldName la colonne
	 * @return true si il a le droit, false sinon
	 */
	bool canRead(const QString& uid, const QString& tableName, const QString& fieldName);

	/**
	 * @brief canRead retourne true si le login uid a droit de lire une colonne d'une table
	 * @param uid       le login
	 * @param tableName la table
	 * @param fieldName la colonne
	 * @return true si il a le droit, false sinon
	 */
	bool canWrite(const QString& uid,const QString& tableName, const QString& fieldName);

	/**
	 * @brief canAdd retourne true si le login uid a droit d'ajouter une table
	 * @param uid           le login
	 * @param tableName     la table
	 * @return true si il a le droit, false sinon
	 */
	bool canAdd(const QString& uid, const QString& tableName);

	/**
	 * @brief canDelete retourne true si le login uid a droit de supprimer une table
	 * @param uid       le login
	 * @param tableName la table
	 * @return true si il a le droit, false sinon
	 */
	bool canDelete(const QString& uid, const QString& tableName);

private:

	/**
	 * @brief chercheTab verifie la presence d'un string dans une liste de string
	 * @param str  la liste de string
	 * @param str2 le string à trouvé
	 * @return l'indice du string dans la liste, sinon -1
	 */
	int chercheTab(const StringList& str, const QString& str2);

	/**
	 * @brief chercheField recherche un string dans une chaine de caractere
	 * @param str la chaine
	 * @param str2 le string
	 * @return true si il trouve, false sinon
	 */
	bool chercheField(char* str, const QString& str2);

	/**
	 * @brief attr un attribut
	 */
	LDAPMessage* attr;

	/**
	 * @brief entry une entree
	 */
	LDAPMessage* entry;

	/**
	 * @brief entries les entrees recherche
	 */
	LDAPMessage* entries;

	LDAPConnection con;

};

#endif // DIRECTORY_H
