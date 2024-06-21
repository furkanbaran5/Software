package Package1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public abstract class Database {
    protected final Connection connection;

    protected Database() {
        this.connection = this.connect();
    }

    public Connection connect() {
        try {
        	Connection conn = DriverManager.getConnection(
                    "jdbc:postgresql://ep-purple-dust-a2smnu08.eu-central-1.aws.neon.tech/BorsaKafe?user=BorsaKafe_sipari%C5%9F&password=fd2kGRIm0Hor&sslmode=require", 
                    "BorsaKafe_owner", 
                    "zXtT3lDWB5UO");
            if (conn != null) {
                System.out.println("Connected to the database!");
                return conn;
            } else {
                System.out.println("Failed to make connection!");
            }

        } catch (SQLException e) {
            System.err.format("SQL State: %s\n%s", e.getSQLState(), e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}