# NOTE

We will use the user "postgres"
We wouldn't use the default database "postgres" of default user "postgres"
We will use the database "ods" as our database
We wouldn't use default schema "public"
We will use the schema "ods" as our schema

"-U postgres" means the user "postgres"
"-d ods" means the database "ods"
"-N public" means all schemas except "public"
"D:\pg_dump.sql" means the sql file path





# How to dump

## Open terminal

## Locate to pg_dump if you are using Windows

## Dump to a sql file

pg_dump -U postgres -d ods -N public -O --no-comments > D:\pg_dump.sql





# How to restore

## Open terminal

## Locate to pg_dump if you are using Windows

## Execute the following commands

psql -U postgres -c "DROP DATABASE IF EXISTS ods;"

psql -U postgres -c "CREATE DATABASE ods WITH OWNER postgres;"

psql -U postgres -d ods < D:\pg_dump.sql