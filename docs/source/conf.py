from __future__ import annotations

import os
from pathlib import Path

project = "TypeSafeRegister"
author = "Stephan Ka"
copyright = "2026, Stephan Ka"

extensions = ["breathe", "sphinxcontrib.mermaid"]
templates_path = ["_templates"]
exclude_patterns: list[str] = []
html_theme = "alabaster"

doxygen_xml_dir = os.environ.get("TYPESAFE_REGISTER_DOXYGEN_XML_DIR")
if not doxygen_xml_dir:
    raise RuntimeError(
        "TYPESAFE_REGISTER_DOXYGEN_XML_DIR is required. Build documentation with "
        "the CMake sphinx-docs target."
    )

breathe_projects = {"TypeSafeRegister": str(Path(doxygen_xml_dir))}
breathe_default_project = "TypeSafeRegister"