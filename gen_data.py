#!/bin/env python3
import random

organizations = [
    "BMSTU",
    "KF BMSTU",
    "KGU",
    "Harvard University",
    "Stanford University",
    "Massachusetts Institute of Technology (MIT)",
    "California Institute of Technology (Caltech)",
    "Oxford University",
    "Cambridge University",
    "University of Chicago",
    "University College London (UCL)",
    "Princeton University",
    "Imperial College London",
    "Yale University",
    "University of Pennsylvania",
    "Columbia University",
    "University of California, Berkeley",
    "University of California, Los Angeles (UCLA)",
    "University of Tokyo",
    "University of Toronto",
    "McGill University"
]

basis_desc = [
        "Policy",
        "Privacy",
        "Control",
        "Security",
        ]

investigation_types = [
    "Investigation::Type::FinancialControl",
    "Investigation::Type::StateProcurementControl",
    "Investigation::Type::StateServicesControl"
]

for _ in range(20):
    investigation_id = random.randint(10000000, 99999999)
    organization = random.choice(organizations)
    date = f"Date(2023, {random.randint(1, 12)}, {random.randint(1, 28)})"
    description = "This is description"
    investigation_type = random.choice(investigation_types)
    basis_id = random.randint(10000000, 99999999)
    basis_date = f"Date(2023, {random.randint(1, 12)}, {random.randint(1, 28)})"
    basis_description = f"{random.choice(basis_desc)}"

    row = f"storage.add(Investigation(\n" \
          f"    {investigation_id},\n" \
          f"    \"{organization}\",\n" \
          f"    {date},\n" \
          f"    \"{description}\",\n" \
          f"    {investigation_type},\n" \
          f"    Basis({basis_id}, {basis_date}, \"{basis_description}\")));\n"

    print(row)
