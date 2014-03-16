#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


CREATE TABLE Requisition(
        RequisitionId                 Integer NOT NULL ,
        CountryCode                   Integer NOT NULL ,
        ForCostEstimate               Integer ,
        ForPurchase                   Integer ,
        WhDispatchRelease             Integer ,
        RequisitionDate               Date ,
        DesiredDeliveryDate           Date ,
        TransportMeans                Enum ("Sea","Road","Plane","Rail") ,
        LocalisationId                Integer NOT NULL ,
        LocalisationId_1              Integer NOT NULL ,
        CurrencyId                    Int ,
        AgreementDate                 Date NOT NULL ,
        PersonId                      Int ,
        AgreementDate_Manager         Date NOT NULL ,
        PersonId_2                    Int ,
        AgreementDate_Requester       Date NOT NULL ,
        PersonId_3                    Int ,
        AgreementDate_Logistics       Date NOT NULL ,
        PersonId_4                    Int ,
        AgreementDate_GlobalFleetBase Date NOT NULL ,
        PersonId_5                    Int ,
        PRIMARY KEY (RequisitionId ,CountryCode )
)ENGINE=InnoDB;


CREATE TABLE GPS(
        GpsId    int (11) Auto_increment  NOT NULL ,
        xDeg     Integer ,
        xMin     Integer ,
        xSec     Integer ,
        xDir     Enum ("N","W","S","E") ,
        yDeg     Integer ,
        yMin     Integer ,
        ySec     Integer ,
        yDir     Enum ("N","W","S","E") ,
        Comments Text ,
        PRIMARY KEY (GpsId )
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


CREATE TABLE Localisation(
        LocalisationId Integer NOT NULL ,
        CommonName     Varchar (255) NOT NULL ,
        MailingAddress Varchar (500) NOT NULL ,
        Code           Varchar (20) ,
        CountryId      Integer ,
        GpsId          Int NOT NULL ,
        PRIMARY KEY (LocalisationId )
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
        PersonId       int (11) Auto_increment  NOT NULL ,
        LastName       Varchar (255) ,
        FirstName      Varchar (255) ,
        PhoneNumber    Varchar (255) ,
        Email          Varchar (25) ,
        DriverId       Integer ,
        LocalisationId Integer NOT NULL ,
        FunctionId     Integer ,
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
        LocalisationId  Integer NOT NULL ,
        PRIMARY KEY (PersonId ,CountryCode ,WaybillId ,LocalisationId )
)ENGINE=InnoDB;


CREATE TABLE Reception(
        ReceptionDate     Date NOT NULL ,
        ReceptionComments Text ,
        PersonId          Int NOT NULL ,
        CountryCode       Integer NOT NULL ,
        WaybillId         Integer NOT NULL ,
        LocalisationId    Integer NOT NULL ,
        PRIMARY KEY (PersonId ,CountryCode ,WaybillId ,LocalisationId )
)ENGINE=InnoDB;


CREATE TABLE Transport(
        TransportDate  Date NOT NULL ,
        CountryCode    Integer NOT NULL ,
        WaybillId      Integer NOT NULL ,
        DriverId       Integer NOT NULL ,
        LocalisationId Integer NOT NULL ,
        PRIMARY KEY (CountryCode ,WaybillId ,DriverId ,LocalisationId )
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

ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_LocalisationId FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_LocalisationId_1 FOREIGN KEY (LocalisationId_1) REFERENCES Localisation(LocalisationId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_CurrencyId FOREIGN KEY (CurrencyId) REFERENCES Currency(CurrencyId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_PersonId_2 FOREIGN KEY (PersonId_2) REFERENCES Person(PersonId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_PersonId_3 FOREIGN KEY (PersonId_3) REFERENCES Person(PersonId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_PersonId_4 FOREIGN KEY (PersonId_4) REFERENCES Person(PersonId);
ALTER TABLE Requisition ADD CONSTRAINT FK_Requisition_PersonId_5 FOREIGN KEY (PersonId_5) REFERENCES Person(PersonId);
ALTER TABLE Localisation ADD CONSTRAINT FK_Localisation_CountryId FOREIGN KEY (CountryId) REFERENCES Country(CountryId);
ALTER TABLE Localisation ADD CONSTRAINT FK_Localisation_GpsId FOREIGN KEY (GpsId) REFERENCES GPS(GpsId);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_RequisitionId FOREIGN KEY (RequisitionId) REFERENCES Requisition(RequisitionId);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_CountryCode_Requisition FOREIGN KEY (CountryCode_Requisition) REFERENCES Requisition(CountryCode);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_VehicleId FOREIGN KEY (VehicleId) REFERENCES Vehicle(VehicleId);
ALTER TABLE Waybill ADD CONSTRAINT FK_Waybill_ContractId FOREIGN KEY (ContractId) REFERENCES Contract(ContractId);
ALTER TABLE Person ADD CONSTRAINT FK_Person_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE Person ADD CONSTRAINT FK_Person_LocalisationId FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId);
ALTER TABLE Person ADD CONSTRAINT FK_Person_FunctionId FOREIGN KEY (FunctionId) REFERENCES Function(FunctionId);
ALTER TABLE Vehicle ADD CONSTRAINT FK_Vehicle_VehicleTypeId FOREIGN KEY (VehicleTypeId) REFERENCES VehicleType(VehicleTypeId);
ALTER TABLE Vehicle ADD CONSTRAINT FK_Vehicle_ProviderId FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId);
ALTER TABLE Contract ADD CONSTRAINT FK_Contract_ProviderId FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId);
ALTER TABLE Contract ADD CONSTRAINT FK_Contract_ContractTypeId FOREIGN KEY (ContractTypeId) REFERENCES ContractType(ContractTypeId);
ALTER TABLE Driver ADD CONSTRAINT FK_Driver_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_CountryCode FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_WaybillId FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId);
ALTER TABLE Loading ADD CONSTRAINT FK_Loading_LocalisationId FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_PersonId FOREIGN KEY (PersonId) REFERENCES Person(PersonId);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_CountryCode FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_WaybillId FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId);
ALTER TABLE Reception ADD CONSTRAINT FK_Reception_LocalisationId FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_CountryCode FOREIGN KEY (CountryCode) REFERENCES Waybill(CountryCode);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_WaybillId FOREIGN KEY (WaybillId) REFERENCES Waybill(WaybillId);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE Transport ADD CONSTRAINT FK_Transport_LocalisationId FOREIGN KEY (LocalisationId) REFERENCES Localisation(LocalisationId);
ALTER TABLE DriverProvider ADD CONSTRAINT FK_DriverProvider_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE DriverProvider ADD CONSTRAINT FK_DriverProvider_ProviderId FOREIGN KEY (ProviderId) REFERENCES Provider(ProviderId);
ALTER TABLE DriverSDrivingLicence ADD CONSTRAINT FK_DriverSDrivingLicence_DriverId FOREIGN KEY (DriverId) REFERENCES Driver(DriverId);
ALTER TABLE DriverSDrivingLicence ADD CONSTRAINT FK_DriverSDrivingLicence_DrivingLicenceTypeId FOREIGN KEY (DrivingLicenceTypeId) REFERENCES DrivingLicenceType(DrivingLicenceTypeId);
