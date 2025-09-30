# hinge

Hinge is a lightweight, purpose-built scripting language optimized for API development, web automation, and data analytics. It combines a minimal footprint with expressive syntax for rapid prototyping and service integration.

## Why Hinge?

Most scripting languages are either too general-purpose or too heavy for targeted service work. Hinge aims to strike a balance: minimal syntax, built-in primitives for HTTP requests and JSON handling, and a clear standard library for working with APIs and data.

Hinge is currently under active development.

## Features (Planned)

- Simple, expressive syntax
- Native support for:
  - HTTP requests
  - JSON parsing and manipulation
  - Data extraction and transformation
  - File I/O (with limits)
- Minimal runtime, portable interpreter
- Embedded mode for integration into existing apps
- Optional CLI tool for scripting automation

## Example (Target Syntax)

```hinge
response = http.get("https://api.example.com/users")
print(response.body[0].email)

Getting Started

Hinge is not yet stable. If you’re interested in contributing, exploring, or following progress:
	1.	Clone the repository:

git clone https://github.com/MinakiLabs-Official/hinge.git
cd hinge

	2.	View example scripts:

cd examples
cat hello.hinge

	3.	Run the interpreter (once implemented):

python src/main.py examples/hello.hinge

Interpreter implementation is in progress. A basic lexer/parser will be included in the first milestone.

Project Structure

hinge/
├── src/           # Interpreter source code
├── examples/      # Hinge script examples
├── tests/         # Test suite
├── README.md
├── LICENSE
└── .gitignore

Contributing

Contributions are welcome. Planned areas for contribution include:
	•	Interpreter design (lexer, parser, runtime)
	•	Syntax definition and refinement
	•	Standard library design (especially API and JSON utilities)
	•	CLI tooling and REPL

To discuss architecture or suggest improvements, feel free to open an issue or PR.

License

MIT License. See LICENSE file for details.

---

Let me know if you'd like:

- A real `.hinge` example file to match that syntax
- A `CONTRIBUTING.md` or issue/PR templates
- A `src/main.py` starter skeleton for the interpreter

Want to move on to the interpreter structure next?
