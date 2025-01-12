CREATE TABLE VersionControl (
   CurrentVersion INT PRIMARY KEY
);

INSERT INTO VersionControl (CurrentVersion) VALUES (0);

CREATE TABLE VersionHistory (
   VersionNumber INT identity(1, 1) not null PRIMARY KEY,
   ProcedureName NVARCHAR(100),
   TableName NVARCHAR(50) NULL,
   ColumnName NVARCHAR(50) NULL,
   OldColumnType NVARCHAR(50) NULL,
   NewColumnType NVARCHAR(50) NULL,
   DefaultValue NVARCHAR(50) NULL,
   ColumnAdded NVARCHAR(50) NULL,
   ColumnAddedType NVARCHAR(50) NULL,
   ForeignKeyTable NVARCHAR(50) NULL,
   ForeignKeyColumn NVARCHAR(50) NULL,
   ColumnsDefinition NVARCHAR(MAX) NULL
);

CREATE OR ALTER PROCEDURE ModifyColumnType 
    @table_name NVARCHAR(50), 
    @column_name NVARCHAR(50), 
    @new_type NVARCHAR(50),
    @new_version int=1
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    DECLARE @old_type NVARCHAR(50);
    SELECT @old_type = DATA_TYPE 
    FROM INFORMATION_SCHEMA.COLUMNS
    WHERE TABLE_NAME = @table_name AND COLUMN_NAME = @column_name;
    DECLARE @length AS VARCHAR(50)
        SET @length = (
            SELECT T.CHARACTER_MAXIMUM_LENGTH
            FROM INFORMATION_SCHEMA.COLUMNS T
            WHERE TABLE_NAME = @table_name and COLUMN_NAME = @column_name
        )
    IF @length is not null
        SET @old_type = @old_type + '(' + @length + ')'
    SET @sql = 'ALTER TABLE ' + @table_name + ' ALTER COLUMN ' + @column_name + ' ' + @new_type;
    EXEC sp_executesql @sql;
    if @new_version = 1
    BEGIN
            INSERT INTO VersionHistory (ProcedureName, TableName, ColumnName, OldColumnType, NewColumnType, DefaultValue, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition)
            VALUES ('ModifyColumnType', @table_name, @column_name, @old_type, @new_type, NULL, NULL, NULL, NULL, NULL, NULL);
            UPDATE VersionControl SET CurrentVersion = (SELECT MAX(VersionNumber) FROM VersionHistory)
    END
END;
GO

CREATE OR ALTER PROCEDURE RollbackColumnType
    @table_name NVARCHAR(50),
    @column_name NVARCHAR(50),
    @old_type NVARCHAR(50)
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table_name + ' ALTER COLUMN ' + @column_name + ' ' + @old_type;
    EXEC sp_executesql @sql;
END;
GO


CREATE OR ALTER PROCEDURE AddDefaultConstraint 
    @table_name NVARCHAR(50), 
    @column_name NVARCHAR(50), 
    @default_value NVARCHAR(50),
    @new_version int=1
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table_name + ' ADD CONSTRAINT DF_' + @table_name + '_' + @column_name + ' DEFAULT ' + @default_value + ' FOR ' + @column_name;
    EXEC sp_executesql @sql;
    if @new_version = 1
    BEGIN
        INSERT INTO VersionHistory (ProcedureName, TableName, ColumnName, DefaultValue, OldColumnType, NewColumnType, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition)
        VALUES ('AddDefaultConstraint', @table_name, @column_name, @default_value, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
        UPDATE VersionControl SET CurrentVersion = (SELECT MAX(VersionNumber) FROM VersionHistory);
    END
END;
GO

CREATE OR ALTER PROCEDURE RollbackDefaultConstraint 
    @table NVARCHAR(50),
    @column NVARCHAR(50)
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table + ' DROP CONSTRAINT DF_' + @table + '_' + @column;
    EXEC sp_executesql @sql;
END;
GO


CREATE OR ALTER PROCEDURE CreateNewTable 
    @table_name NVARCHAR(50),
    @columns NVARCHAR(MAX),
    @new_version int=1
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'CREATE TABLE ' + @table_name + ' (' + @columns + ')';
    EXEC sp_executesql @sql;
    if @new_version = 1
    BEGIN
        INSERT INTO VersionHistory (ProcedureName, TableName, ColumnName, OldColumnType, NewColumnType, DefaultValue, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition)
        VALUES ('CreateNewTable', @table_name, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, @columns);
        UPDATE VersionControl SET CurrentVersion = (SELECT MAX(VersionNumber) FROM VersionHistory);
    END
END;
GO

CREATE OR ALTER PROCEDURE RollbackCreateTable
    @table_name NVARCHAR(50)
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'DROP TABLE ' + @table_name;
    EXEC sp_executesql @sql;
END;
GO


CREATE OR ALTER PROCEDURE AddColumn 
    @table_name NVARCHAR(50), 
    @column_name NVARCHAR(50), 
    @column_type NVARCHAR(50),
    @new_version int=1
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table_name + ' ADD ' + @column_name + ' ' + @column_type;
    EXEC sp_executesql @sql;
    if @new_version = 1
    BEGIN
        INSERT INTO VersionHistory (ProcedureName, TableName, ColumnName, OldColumnType, NewColumnType, DefaultValue, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition)
        VALUES ('AddColumn', @table_name, @column_name, NULL, NULL, NULL, @column_name, @column_type, NULL, NULL, NULL);
        UPDATE VersionControl SET CurrentVersion = (SELECT MAX(VersionNumber) FROM VersionHistory);
    END
END;
GO

CREATE OR ALTER PROCEDURE RollbackAddColumn
    @table NVARCHAR(50),
    @column NVARCHAR(50)
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table + ' DROP COLUMN ' + @column;
    EXEC sp_executesql @sql;
END;
GO

CREATE OR ALTER PROCEDURE AddForeignKey 
    @table_name NVARCHAR(50), 
    @column_name NVARCHAR(50), 
    @referenced_table NVARCHAR(50),
    @referenced_column NVARCHAR(50),
    @new_version int=1
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table_name + 
               ' ADD CONSTRAINT FK_' + @table_name + '_' + @column_name +
               ' FOREIGN KEY (' + @column_name + ') REFERENCES ' + @referenced_table + '(' + @referenced_column + ')';
    EXEC sp_executesql @sql;
    if @new_version = 1
    BEGIN
        INSERT INTO VersionHistory (ProcedureName, TableName, ColumnName, OldColumnType, NewColumnType, DefaultValue, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition)
        VALUES ('AddForeignKey', @table_name, @column_name, NULL, NULL, NULL, NULL, NULL, @referenced_table, @referenced_column, NULL);

        UPDATE VersionControl SET CurrentVersion = (SELECT MAX(VersionNumber) FROM VersionHistory);
    END
END;
GO

CREATE OR ALTER PROCEDURE RollbackForeignKey 
    @table NVARCHAR(50),
    @column NVARCHAR(50)
AS
BEGIN
    DECLARE @sql NVARCHAR(MAX);
    SET @sql = 'ALTER TABLE ' + @table + ' DROP CONSTRAINT FK_' + @table + '_' + @column;
    EXEC sp_executesql @sql;
END;
GO

CREATE OR ALTER PROCEDURE UpdateVersion 
    @version INT
AS
BEGIN
    DECLARE @currentVersion INT;
    SELECT @currentVersion = ISNULL(CurrentVersion, 0) FROM VersionControl;
    IF @version = @currentVersion
    BEGIN
        PRINT 'Already at specified version';
        RETURN;
    END

    IF @version > @currentVersion
    BEGIN
        PRINT 'Going up';
        DECLARE history_cursor CURSOR FOR
        SELECT VersionNumber, ProcedureName, TableName, ColumnName, OldColumnType, NewColumnType, 
               DefaultValue, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition
        FROM VersionHistory
        WHERE VersionNumber > @currentVersion AND VersionNumber <= @version
        ORDER BY VersionNumber ASC;
        DECLARE @verNum INT, @proc NVARCHAR(100), @table NVARCHAR(50), @column NVARCHAR(50),
                @oldType NVARCHAR(50), @newType NVARCHAR(50), @default NVARCHAR(50),
                @colAdded NVARCHAR(50), @colType NVARCHAR(50), @fkTable NVARCHAR(50), @fkCol NVARCHAR(50), @cdef NVARCHAR(MAX);
        OPEN history_cursor;
        FETCH NEXT FROM history_cursor INTO @verNum, @proc, @table, @column, @oldType, @newType,
                                            @default, @colAdded, @colType, @fkTable, @fkCol, @cdef;
        WHILE @@FETCH_STATUS = 0
        BEGIN
            IF @proc = 'ModifyColumnType'
            BEGIN
                EXEC ModifyColumnType @table, @column, @newType, 0;
            END
            ELSE IF @proc = 'AddDefaultConstraint'
            BEGIN
                EXEC AddDefaultConstraint @table, @column, @default, 0;
            END
            ELSE IF @proc = 'CreateNewTable'
            BEGIN
                IF @cdef IS NOT NULL
                BEGIN
                    EXEC CreateNewTable @table, @cdef, 0;
                END
            END
            ELSE IF @proc = 'AddColumn'
            BEGIN
                EXEC AddColumn @table, @colAdded, @colType, 0;
            END
            ELSE IF @proc = 'AddForeignKey'
            BEGIN
                EXEC AddForeignKey @table, @column, @fkTable, @fkCol, 0;
            END
            UPDATE VersionControl SET CurrentVersion = @verNum;
            FETCH NEXT FROM history_cursor INTO @verNum, @proc, @table, @column, @oldType, @newType,
                                                @default, @colAdded, @colType, @fkTable, @fkCol, @cdef;
        END
        CLOSE history_cursor;
        DEALLOCATE history_cursor;
    END

    ELSE IF @version < @currentVersion
    BEGIN
        PRINT 'Going down';
        DECLARE rollback_cursor CURSOR FOR
        SELECT VersionNumber, ProcedureName, TableName, ColumnName, OldColumnType, NewColumnType,
               DefaultValue, ColumnAdded, ColumnAddedType, ForeignKeyTable, ForeignKeyColumn, ColumnsDefinition
        FROM VersionHistory
        WHERE VersionNumber <= @currentVersion AND VersionNumber > @version
        ORDER BY VersionNumber DESC;
        OPEN rollback_cursor;
        FETCH NEXT FROM rollback_cursor INTO @verNum, @proc, @table, @column, @oldType, @newType,
                                             @default, @colAdded, @colType, @fkTable, @fkCol, @cdef;
        WHILE @@FETCH_STATUS = 0
        BEGIN
            IF @proc = 'ModifyColumnType'
                EXEC RollbackColumnType @table, @column, @oldType;
            ELSE IF @proc = 'AddDefaultConstraint'
                EXEC RollbackDefaultConstraint  @table, @column;
            ELSE IF @proc = 'CreateNewTable'
                BEGIN
                    IF @cdef IS NOT NULL
                    BEGIN
                        EXEC RollbackCreateTable @table;
                    END
                END
            ELSE IF @proc = 'AddColumn'
                EXEC RollbackAddColumn @table, @colAdded;
            ELSE IF @proc = 'AddForeignKey'
                EXEC RollbackForeignKey  @table, @column;
            SET @currentVersion = @verNum - 1;
            UPDATE VersionControl SET CurrentVersion = @currentVersion;
            FETCH NEXT FROM rollback_cursor INTO @verNum, @proc, @table, @column, @oldType, @newType,
                                                 @default, @colAdded, @colType, @fkTable, @fkCol, @cdef;
        END
        CLOSE rollback_cursor;
        DEALLOCATE rollback_cursor;
    END
END;
GO

EXEC ModifyColumnType 'Managers', 'ManagerID', 'INT';
GO
EXEC RollbackColumnType 'Managers', 'ManagerID', 'VARCHAR(50)';
GO

EXEC AddDefaultConstraint 'Artists', 'Active', '1';
GO
EXEC RollbackDefaultConstraint 'Artists', 'Active';
GO

EXEC CreateNewTable 'Merchandise', 'MerchID INT PRIMARY KEY';
GO
EXEC RollbackCreateTable 'Merchandise';
GO

EXEC AddColumn 'Projects', 'Budget', 'DECIMAL(9,2)';
GO
EXEC RollbackAddColumn 'Projects', 'Budget';
GO

EXEC AddForeignKey 'Employees', 'HQID', 'Headquarters', 'HQID';
GO
EXEC RollbackForeignKey 'Employees', 'HQID';
GO

SELECT * FROM VersionHistory;
SELECT * FROM VersionControl;

EXEC UpdateVersion @version = 2;
GO