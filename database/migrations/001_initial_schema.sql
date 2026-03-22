-- 1. ОПЕРАТОРЫ (юрлица)
CREATE TABLE IF NOT EXISTS operators (
    id SERIAL PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    inn VARCHAR(12) NOT NULL UNIQUE,
    kpp VARCHAR(9),
    ogrn VARCHAR(15),
    phone VARCHAR(20),
    email VARCHAR(100),
    contact_person VARCHAR(200) NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 2. СТАНЦИИ
CREATE TABLE IF NOT EXISTS stations (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    city VARCHAR(100) NOT NULL,
    frequency VARCHAR(20) NOT NULL,
    operator_id INTEGER NOT NULL REFERENCES operators(id) ON DELETE RESTRICT,
    is_active BOOLEAN DEFAULT TRUE,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- 3. ЛИЦЕНЗИИ
CREATE TABLE IF NOT EXISTS licenses (
    id SERIAL PRIMARY KEY,
    license_number VARCHAR(50) NOT NULL UNIQUE,
    issue_date DATE NOT NULL,
    expiry_date DATE NOT NULL,
    station_id INTEGER NOT NULL REFERENCES stations(id) ON DELETE RESTRICT,
    is_valid BOOLEAN DEFAULT TRUE,
    scan_path VARCHAR(500),
    notes TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    CHECK (expiry_date > issue_date)
);
