from transformers import pipeline

unmasker = pipeline('fill-mask', model='bert-base-uncased')

result = unmasker("Artificial Intelligence [MASK] take over the world.")
print(result)
