
CREATE TABLE Requisition(
	RequisitionId                  INTEGER NOT NULL ,
	CountryCode                    INTEGER NOT NULL ,
	ForCostEstimate                INTEGER ,
	ForPurchase                    INTEGER ,
	WhDispatchRelease              INTEGER ,
	RequisitionDate                NUMERIC ,
	DesiredDeliveryDate            NUMERIC ,
	TransportMeans                 TEXT   ,
	LocalisationId                 INTEGER NOT NULL ,
	LocalisationId_1               INTEGER NOT NULL ,
	CurrencyId                     INTEGER ,
	AgreementDate                  NUMERIC NOT NULL ,
	PersonId                       INTEGER ,
	AgreementDate_Manager          NUMERIC NOT NULL ,
	PersonId_2                     INTEGER ,
	AgreementDate_Requester        NUMERIC NOT NULL ,
	PersonId_3                     INTEGER ,
	AgreementDate_Logistics        NUMERIC NOT NULL ,
	PersonId_4                     INTEGER ,
	AgreementDate_GlobalFleetBase  NUMERIC NOT NULL ,
	PersonId_5                     INTEGER ,
	PRIMARY KEY (RequisitionId,CountryCode) ,
	CHECK (TransportMeans IN ("Sea","Road","Plane","Rail")) ,
	
	FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId),
	FOREIGN KEY (LocalisationId_1) REFERENCES Localisation(LocalisationId),
	FOREIGN KEY (CurrencyId) REFERENCES Currency(CurrencyId),
	FOREIGN KEY (PersonId) REFERENCES Person(PersonId),
	FOREIGN KEY (PersonId_2) REFERENCES Person(PersonId),
	FOREIGN KEY (PersonId_3) REFERENCES Person(PersonId),
	FOREIGN KEY (PersonId_4) REFERENCES Person(PersonId),
	FOREIGN KEY (PersonId_5) REFERENCES Person(PersonId)
);

CREATE TABLE GPS(
	GpsId     INTEGER NOT NULL ,
	xDeg      INTEGER ,
	xMin      INTEGER ,
	xSec      INTEGER ,
	xDir      TEXT   ,
	yDeg      INTEGER ,
	yMin      INTEGER ,
	ySec      INTEGER ,
	yDir      TEXT   ,
	Comments  TEXT ,
	PRIMARY KEY (GpsId) ,
	CHECK (xDir IN ("N","W","S","E")),
	CHECK yDir IN ("N","W","S","E"))
);

CREATE TABLE Country(
	CountryId  INTEGER NOT NULL ,
	iso        TEXT NOT NULL ,
	name       TEXT NOT NULL ,
	nicename   TEXT NOT NULL ,
	iso3       TEXT NOT NULL ,
	phonecode  INTEGER NOT NULL ,
	PRIMARY KEY (CountryId)
);

CREATE TABLE Currency(
	CurrencyId  INTEGER  NOT NULL ,
	Name        TEXT NOT NULL ,
	Symbol      TEXT NOT NULL ,
	PRIMARY KEY (CurrencyId)
);

CREATE TABLE Localisation(
	LocalisationId  INTEGER NOT NULL ,
	CommonName      TEXT NOT NULL ,
	MailingAddress  TEXT NOT NULL ,
	Code            TEXT ,
	CountryId       INTEGER ,
	GpsId           INTEGER NOT NULL ,
	PRIMARY KEY (LocalisationId) ,
	
	FOREIGN KEY (CountryId) REFERENCES Country(CountryId),
	FOREIGN KEY (GpsId) REFERENCES GPS(GpsId)
);

CREATE TABLE Waybill(
	CountryCode              INTEGER NOT NULL ,
	WaybillId                INTEGER NOT NULL ,
	RequestDate              NUMERIC NOT NULL ,
	TransportMean            TEXT  NOT NULL  ,
	RequisitionId            INTEGER ,
	CountryCode_Requisition  INTEGER ,
	VehicleId                INTEGER ,
	ContractId               INTEGER ,
	PRIMARY KEY (CountryCode,WaybillId) ,
	CHECK (TransportMean IN ("Sea","Road","Plane","Rail")) ,
	
	FOREIGN KEY (RequisitionId) REFERENCES Requisition(RequisitionId),
	FOREIGN KEY (CountryCode_Requisition) REFERENCES Requisition(CountryCode),
	FOREIGN KEY (VehicleId) REFERENCES Vehicle(VehicleId),
	FOREIGN KEY (ContractId) REFERENCES Contract(ContractId)
);

CREATE TABLE Person(
	PersonId        INTEGER  NOT NULL ,
	LastName        TEXT ,
	FirstName       TEXT ,
	PhoneNumber     TEXT ,
	Email           TEXT ,
	DriverId        INTEGER ,
	LocalisationId  INTEGER NOT NULL ,
	FunctionId      INTEGER ,
	PRIMARY KEY (PersonId) ,
	
	FOREIGN KEY (DriverId) REFERENCES Driver(DriverId),
	FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId),
	FOREIGN KEY (FunctionId) REFERENCES Function(FunctionId)
);

CREATE TABLE Vehicle(
	VehicleId      INTEGER NOT NULL ,
	MaxWeight      INTEGER ,
	MaxVolume      INTEGER ,
	MaxAutonomy    INTEGER ,
	VehicleTypeId  INTEGER ,
	ProviderId     INTEGER ,
	PRIMARY KEY (VehicleId) ,
	
	FOREIGN KEY (VehicleTypeId) REFERENCES VehicleType(VehicleTypeId),
	FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId)
);

CREATE TABLE VehicleType(
	VehicleTypeId  INTEGER  NOT NULL ,
	Name           TEXT NOT NULL ,
	Mean           TEXT  NOT NULL  ,
	PRIMARY KEY (VehicleTypeId) ,
	CHECK (Mean IN ("Sea","Road","Plane","Rail"))
);

CREATE TABLE Provider(
	ProviderId  INTEGER NOT NULL ,
	Name        TEXT NOT NULL ,
	Licence     NONE ,
	PRIMARY KEY (ProviderId)
);

CREATE TABLE Contract(
	ContractId      INTEGER NOT NULL ,
	NumericVersion  NONE ,
	ProviderId      INTEGER ,
	ContractTypeId  INTEGER ,
	PRIMARY KEY (ContractId) ,
	
	FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId),
	FOREIGN KEY (ContractTypeId) REFERENCES ContractType(ContractTypeId)
);

CREATE TABLE ContractType(
	ContractTypeId  INTEGER NOT NULL ,
	Name            TEXT NOT NULL ,
	PRIMARY KEY (ContractTypeId)
);

CREATE TABLE Driver(
	DriverId  INTEGER NOT NULL ,
	PersonId  INTEGER ,
	PRIMARY KEY (DriverId) ,
	
	FOREIGN KEY (PersonId) REFERENCES Person(PersonId)
);

CREATE TABLE DrivingLicenceType(
	DrivingLicenceTypeId  INTEGER NOT NULL ,
	Category              TEXT ,
	Range                 TEXT   ,
	PRIMARY KEY (DrivingLicenceTypeId) ,
	CHECK (Range IN ("Global","International","National"))
);

CREATE TABLE Function(
	FunctionId  INTEGER NOT NULL ,
	Name        TEXT NOT NULL ,
	PRIMARY KEY (FunctionId)
);

CREATE TABLE Loading(
	LoadingDate      NUMERIC NOT NULL ,
	LoadingComments  TEXT ,
	PersonId         INTEGER NOT NULL ,
	CountryCode      INTEGER NOT NULL ,
	WaybillId        INTEGER NOT NULL ,
	LocalisationId   INTEGER NOT NULL ,
	PRIMARY KEY (PersonId,CountryCode,WaybillId,LocalisationId) ,
	
	FOREIGN KEY (PersonId) REFERENCES Person(PersonId),
	FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode),
	FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId),
	FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId)
);

CREATE TABLE Reception(
	ReceptionDate      NUMERIC NOT NULL ,
	ReceptionComments  TEXT ,
	PersonId           INTEGER NOT NULL ,
	CountryCode        INTEGER NOT NULL ,
	WaybillId          INTEGER NOT NULL ,
	LocalisationId     INTEGER NOT NULL ,
	PRIMARY KEY (PersonId,CountryCode,WaybillId,LocalisationId) ,
	
	FOREIGN KEY (PersonId) REFERENCES Person(PersonId),
	FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode),
	FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId),
	FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId)
);

CREATE TABLE Transport(
	TransportDate   NUMERIC NOT NULL ,
	CountryCode     INTEGER NOT NULL ,
	WaybillId       INTEGER NOT NULL ,
	DriverId        INTEGER NOT NULL ,
	LocalisationId  INTEGER NOT NULL ,
	PRIMARY KEY (CountryCode,WaybillId,DriverId,LocalisationId) ,
	
	FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode),
	FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId),
	FOREIGN KEY (DriverId) REFERENCES Driver(DriverId),
	FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId)
);

CREATE TABLE DriverProvider(
	DriverId    INTEGER NOT NULL ,
	ProviderId  INTEGER NOT NULL ,
	PRIMARY KEY (DriverId,ProviderId) ,
	
	FOREIGN KEY (DriverId) REFERENCES Driver(DriverId),
	FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId)
);

CREATE TABLE DriverSDrivingLicence(
	Scan                  NONE ,
	LicenceNumber         TEXT ,
	DriverId              INTEGER NOT NULL ,
	DrivingLicenceTypeId  INTEGER NOT NULL ,
	PRIMARY KEY (DriverId,DrivingLicenceTypeId) ,
	
	FOREIGN KEY (DriverId) REFERENCES Driver(DriverId),
	FOREIGN KEY (DrivingLicenceTypeId) REFERENCES DrivingLicenceType(DrivingLicenceTypeId)
);


