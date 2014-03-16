#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


CREATE TABLE Requisition(
	RequisitionId                Integer NOT NULL ,
	CountryCode                  Integer NOT NULL ,
	ForCostEstimate              Integer ,
	ForPurchase                  Integer ,
	WhDispatchRelease            Integer ,
	RequisitionDate              Date ,
	DesiredDeliveryDate          Date ,
	TransportMeans               Enum ("Sea","Road","Plane","Rail") ,
	OriginAddressId              Integer NOT NULL , -- Renom de la colonne : AddressId                     -> OriginAddressId
	DestinationAddressId         Integer NOT NULL , -- Renom de la colonne : AddressId_1                   -> DestinationAddressId
	CurrencyId                   Int ,
	FinanceOfficerAgreementDate  Date NOT NULL ,    -- Renom de la colonne : AgreementDate                 -> FinanceOfficerAgreementDate
	FinanceOfficerPersonId       Int ,              -- Renom de la colonne : PersonId                      -> FinanceOfficerPersonId
	ManagerAgreementDate         Date NOT NULL ,    -- Renom de la colonne : AgreementDate_Manager         -> ManagerAgreementDate
	ManagerPersonId              Int ,              -- Renom de la colonne : PersonId_2                    -> ManagerPersonId
	RequesterAgreementDate       Date NOT NULL ,    -- Renom de la colonne : AgreementDate_Requester       -> RequesterAgreementDate
	RequesterPersonId            Int ,              -- Renom de la colonne : PersonId_3                    -> RequesterPersonId
	LogisticsAgreementDate       Date NOT NULL ,    -- Renom de la colonne : AgreementDate_Logistics       -> LogisticsAgreementDate
	LogisticsPersonId            Int ,              -- Renom de la colonne : PersonId_4                    -> LogisticsPersonId
	GlobalFleetBaseAgreementDate Date NOT NULL ,    -- Renom de la colonne : AgreementDate_GlobalFleetBase -> GlobalFleetBaseAgreementDate
	GlobalFleetBasePersonId      Int ,              -- Renom de la colonne : PersonId_5                    -> GlobalFleetBasePersonId
	PRIMARY KEY (RequisitionId, CountryCode)
)ENGINE=InnoDB;


CREATE TABLE GPS(
	GpsId     int (11) Auto_increment  NOT NULL ,
	xDeg      Integer ,
	xMin      Integer ,
	xSec      Integer ,
	xDir      Enum ("N","W","S","E") ,
	yDeg      Integer ,
	yMin      Integer ,
	ySec      Integer ,
	yDir      Enum ("N","W","S","E") ,
	Comments  Text ,
	AddressId Integer NOT NULL ,
	PRIMARY KEY (GpsId)
)ENGINE=InnoDB;


CREATE TABLE Country(
	CountryId Integer NOT NULL ,
	iso       Char (2) NOT NULL ,
	name      Varchar (80) NOT NULL ,
	nicename  Varchar (80) NOT NULL ,
	iso3      Char (3) NOT NULL ,
	phonecode Int NOT NULL ,
	PRIMARY KEY (CountryId ) ,
	UNIQUE (iso ,iso3 ,phonecode )
)ENGINE=InnoDB;


CREATE TABLE Currency(
	CurrencyId int (11) Auto_increment  NOT NULL ,
	Name       Varchar (255) NOT NULL ,
	Symbol     Varchar (10) NOT NULL ,
	PRIMARY KEY (CurrencyId ) ,
	UNIQUE (Name ,Symbol )
)ENGINE=InnoDB;


CREATE TABLE Address(
	AddressId  Integer NOT NULL ,
	CommonName Varchar (255) NOT NULL ,
	Address    Varchar (500) NOT NULL ,
	Code       Varchar (20) ,
	CountryId  Integer ,
	PRIMARY KEY (AddressId )
)ENGINE=InnoDB;


CREATE TABLE Waybill(
	CountryCode             Integer NOT NULL ,
	WaybillId               Integer NOT NULL ,
	RequestDate             Date NOT NULL ,
	TransportMean           Enum ("Sea","Road","Plane","Rail") NOT NULL ,
	RequisitionId           Integer ,
	CountryCode_Requisition Integer ,
	VehicleId               Integer ,
	ContractId              Integer ,
	PRIMARY KEY (CountryCode ,WaybillId )
)ENGINE=InnoDB;


CREATE TABLE Person(
	PersonId    int (11) Auto_increment  NOT NULL ,
	LastName    Varchar (255) ,
	FirstName   Varchar (255) ,
	PhoneNumber Varchar (255) ,
	Email       Varchar (25) ,
	DriverId    Integer ,
	AddressId   Integer NOT NULL ,
	FunctionId  Integer ,
	PRIMARY KEY (PersonId )
)ENGINE=InnoDB;


CREATE TABLE Vehicle(
        VehicleId     Integer NOT NULL ,
        MaxWeight     Integer ,
        MaxVolume     Integer ,
        MaxAutonomy   Integer ,
        VehicleTypeId Int ,
        ProviderId    Integer ,
        PRIMARY KEY (VehicleId )
)ENGINE=InnoDB;


CREATE TABLE VehicleType(
        VehicleTypeId int (11) Auto_increment  NOT NULL ,
        Name          Varchar (25) NOT NULL ,
        Mean          Enum ("Sea","Road","Plane","Rail") NOT NULL ,
        PRIMARY KEY (VehicleTypeId )
)ENGINE=InnoDB;


CREATE TABLE Provider(
        ProviderId Integer NOT NULL ,
        Name       Varchar (25) NOT NULL ,
        Licence    Blob ,
        PRIMARY KEY (ProviderId )
)ENGINE=InnoDB;


CREATE TABLE Contract(
        ContractId     Integer NOT NULL ,
        NumericVersion Blob ,
        ProviderId     Integer ,
        ContractTypeId Integer ,
        PRIMARY KEY (ContractId )
)ENGINE=InnoDB;


CREATE TABLE ContractType(
        ContractTypeId Integer NOT NULL ,
        Name           Varchar (25) NOT NULL ,
        PRIMARY KEY (ContractTypeId )
)ENGINE=InnoDB;


CREATE TABLE Driver(
        DriverId Integer NOT NULL ,
        PersonId Int ,
        PRIMARY KEY (DriverId )
)ENGINE=InnoDB;


CREATE TABLE DrivingLicenceType(
        DrivingLicenceTypeId Integer NOT NULL ,
        Category             Varchar (25) ,
        Range                Enum ("Global","International","National") ,
        PRIMARY KEY (DrivingLicenceTypeId )
)ENGINE=InnoDB;


CREATE TABLE Function(
        FunctionId Integer NOT NULL ,
        Name       Varchar (25) ,
        PRIMARY KEY (FunctionId ) ,
        UNIQUE (Name )
)ENGINE=InnoDB;


CREATE TABLE Loading(
        LoadingDate     Date NOT NULL ,
        LoadingComments Text ,
        PersonId        Int NOT NULL ,
        CountryCode     Integer NOT NULL ,
        WaybillId       Integer NOT NULL ,
        AddressId       Integer NOT NULL ,
        PRIMARY KEY (PersonId ,CountryCode ,WaybillId ,AddressId )
)ENGINE=InnoDB;


CREATE TABLE Reception(
        ReceptionDate     Date NOT NULL ,
        ReceptionComments Text ,
        PersonId          Int NOT NULL ,
        CountryCode       Integer NOT NULL ,
        WaybillId         Integer NOT NULL ,
        AddressId         Integer NOT NULL ,
        PRIMARY KEY (PersonId ,CountryCode ,WaybillId ,AddressId )
)ENGINE=InnoDB;


CREATE TABLE Transport(
        TransportDate Date NOT NULL ,
        CountryCode   Integer NOT NULL ,
        WaybillId     Integer NOT NULL ,
        DriverId      Integer NOT NULL ,
        AddressId     Integer NOT NULL ,
        PRIMARY KEY (CountryCode ,WaybillId ,DriverId ,AddressId )
)ENGINE=InnoDB;


CREATE TABLE DriverProvider(
        DriverId   Integer NOT NULL ,
        ProviderId Integer NOT NULL ,
        PRIMARY KEY (DriverId ,ProviderId )
)ENGINE=InnoDB;


CREATE TABLE DriverSDrivingLicence(
        Scan                 Blob ,
        LicenceNumber        Varchar (255) ,
        DriverId             Integer NOT NULL ,
        DrivingLicenceTypeId Integer NOT NULL ,
        PRIMARY KEY (DriverId ,DrivingLicenceTypeId )
)ENGINE=InnoDB;

ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_OriginAddressId         FOREIGN KEY (OriginAddressId)         REFERENCES Address(AddressId); -- Renom: AddressId -> OriginAddressId
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_DestinationAddressId    FOREIGN KEY (DestinationAddressId)    REFERENCES Address(AddressId); -- Renom: AddressId_1 -> DestinationAddressId
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_CurrencyId              FOREIGN KEY (CurrencyId)              REFERENCES Currency(CurrencyId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_FinanceOfficerPersonId  FOREIGN KEY (FinanceOfficerPersonId)  REFERENCES Person(PersonId); -- Renom: PersonId   -> FinanceOfficerPersonId
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_ManagerPersonId         FOREIGN KEY (ManagerPersonId)         REFERENCES Person(PersonId); -- Renom: PersonId_2 -> ManagerPersonId
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_RequesterPersonId       FOREIGN KEY (RequesterPersonId)       REFERENCES Person(PersonId); -- Renom: PersonId_3 -> RequesterPersonId
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_LogisticsPersonId       FOREIGN KEY (LogisticsPersonId)       REFERENCES Person(PersonId); -- Renom: PersonId_4 -> LogisticsPersonId
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_GlobalFleetBasePersonId FOREIGN KEY (GlobalFleetBasePersonId) REFERENCES Person(PersonId); -- Renom: PersonId_5 -> GlobalFleetBasePersonId

ALTER TABLE GPS ADD CONSTRAINT FK_GPS_AddressId FOREIGN KEY (AddressId) REFERENCES Address(AddressId);

ALTER TABLE Address ADD CONSTRAINT FK_Address_CountryId FOREIGN KEY (CountryId) REFERENCES Country(CountryId);

ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_RequisitionId FOREIGN KEY (RequisitionId) REFERENCES Requisition(RequisitionId);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_CountryCode_Requisition FOREIGN KEY (CountryCode_Requisition) REFERENCES Requisition(CountryCode);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_VehicleId FOREIGN KEY (VehicleId) REFERENCES Vehicle(VehicleId);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_ContractId FOREIGN KEY (ContractId) REFERENCES Contract(ContractId);

ALTER TABLE Person ADD CONSTRAINT FK_Person_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE Person ADD CONSTRAINT FK_Person_AddressId FOREIGN KEY (AddressId) REFERENCES Address(AddressId);
ALTER TABLE Person ADD CONSTRAINT FK_Person_FunctionId FOREIGN KEY (FunctionId) REFERENCES Function(FunctionId);

ALTER TABLE Vehicle ADD CONSTRAINT FK_Vehicle_VehicleTypeId FOREIGN KEY (VehicleTypeId) REFERENCES VehicleType(VehicleTypeId);
ALTER TABLE Vehicle ADD CONSTRAINT FK_Vehicle_ProviderId FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId);

ALTER TABLE Contract ADD CONSTRAINT FK_Contract_ProviderId FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId);
ALTER TABLE Contract ADD CONSTRAINT FK_Contract_ContractTypeId FOREIGN KEY (ContractTypeId) REFERENCES ContractType(ContractTypeId);

ALTER TABLE Driver ADD CONSTRAINT FK_Driver_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);

ALTER TABLE Loading ADD CONSTRAINT FK_Loading_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_CountryCode FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_WaybillId FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_AddressId FOREIGN KEY (AddressId) REFERENCES Address(AddressId);

ALTER TABLE Reception ADD CONSTRAINT FK_Reception_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_CountryCode FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_WaybillId FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_AddressId FOREIGN KEY (AddressId) REFERENCES Address(AddressId);

ALTER TABLE Transport ADD CONSTRAINT FK_Transport_CountryCode FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_WaybillId FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_AddressId FOREIGN KEY (AddressId) REFERENCES Address(AddressId);

ALTER TABLE DriverProvider ADD CONSTRAINT FK_DriverProvider_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE DriverProvider ADD CONSTRAINT FK_DriverProvider_ProviderId FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId);

ALTER TABLE DriverSDrivingLicence ADD CONSTRAINT FK_DriverSDrivingLicence_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE DriverSDrivingLicence ADD CONSTRAINT FK_DriverSDrivingLicence_DrivingLicenceTypeId FOREIGN KEY (DrivingLicenceTypeId) REFERENCES DrivingLicenceType(DrivingLicenceTypeId);
